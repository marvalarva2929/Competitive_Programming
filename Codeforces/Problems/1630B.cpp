#include <bits/stdc++.h>
#include <string>
#define int long long
#define nl '\n'

using namespace std;

const int mxn = 2e5;
int a[mxn];
int l[mxn + 2];

void solve(int t) {
    int n, k; cin >> n >> k;
    fill(a, a + n, 0);
    fill(l, l + n + 2, 0);

    for (int i = 0; i < n; i++)
        cin >> a[i];
    
    //if (t == 861) {
    //    string b; 
    //    for (int i = 0; i < n; i++)
    //       b += a[i] + '0';

    //    cout << k + 10 << nl;
    //    return; 
    //}

    set<int> allCheck;
    vector<int> all;
    
    for (int i = 0; i < n; i++)
        if (!allCheck.count(a[i]))
            all.push_back(a[i]),
            allCheck.insert(a[i]);

    sort(all.begin(), all.end());

    for (int i = 0; i < n; i++)
        l[a[i] + 1]++;

    for (int i = 1; i <= n + 1; i++)
        l[i] += l[i - 1];

    int x = 0, y = 0;
    
    int mx = 0, my = all.size() - 1;

    for (x = 0; x < all.size(); x++) {
        int rx = l[all[x]];   

        while (y < all.size() - 1  && (l[all[y] + 1] - rx) - (rx + (n - l[all[y] + 1])) < k)
            y++;
        
       // cout << all[x] << " " << all[y] << " " << ( (l[all[y] + 1] - rx)/* - (rx + (n - l[all[y] + 1])) >= k*/)<<  nl;
        //if (y == all.size()) break; 

        if (all[y] - all[x] < all[my] - all[mx] && ( (l[all[y] + 1] - rx) - (rx + (n - l[all[y] + 1])) >= k))
            mx = x,
            my = y;
    }

    cout << all[mx] << " " << all[my] << nl;

    int cnt = 0;
    int cur = 0; 
    int last = 0;
    for (int i = 0; i < n && cnt != k - 1; i++) {
        if (a[i] <= all[my] && a[i] >= all[mx])
            cur++;
        else cur--;
        if (cur > 0) {
            cnt++;
            cout << last + 1 << " " << i + 1 << nl;
            last = i + 1;
            cur = 0;
        }
        if (cnt == k - 1)
            break;
    }
    
    cout << last + 1 << " " << n << nl;
}

signed main() {
   cin.tie(0)->sync_with_stdio(false);

   int t; cin >> t;
    for (int i = 1; i <= t; i++)
        solve(i);
}
