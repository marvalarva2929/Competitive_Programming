#include <bits/stdc++.h>
#define int long long
#define nl '\n'

using namespace std;

const int mxn = 3e5;
    
int cnt[mxn];

void solve(int t) {
    string s; cin >> s;

    int n = s.size(); 
    fill(cnt, cnt + n, 0);

    for (int i = 0; i < n; i++)
        cnt[i] = (s[i] & 1);

    for (int i = 1; i < n; i++)
        cnt[i] += cnt[i - 1];

    int ans = n - cnt[n - 1];    
    int ans2 = INT_MAX; 
    
    for (int i = 0; i < n; i++)
        if (!(s[i] & 1))
            ans = min(ans, cnt[i] + (n - i - 1) - (cnt[n - 1] - cnt[i]));

    for (int i = 1; i < n; i++)
        if ((s[i - 1] & 1) && !(s[i] & 1)) {
            int a;
            if (i == 1)
                a = 0;
            else a = cnt[i - 2];
            ans2 = min(ans2, a + (n - i - 1) - (cnt[n - 1] - cnt[i]));
        }
   
        
    if (ans == INT_MAX) {
        cout << 0 << nl;
        return;
    }
    
    if (ans2 == INT_MAX) {
        cout << ans * (int)(1e12 + 1) << nl;
        return;
    }
        
    cout << min((ans * (int)(1e12 + 1)), (ans2 * ((int)1e12 + 1)) + (int)1e12) << nl;;
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t; cin >> t;
    for (int i = 1; i <= t; i++)
        solve(i);
}
