#include <bits/stdc++.h>
#define int long long
#define pi pair<int, int>
#define ff first
#define ss second
#define nl " \n"

using namespace std;
const int mxn = 2e5;
int cnt[40];
int a[mxn];

pi p2(int x) {
    for (int i = 30; i > 0; i--)
        for (int j = i - 1; j >= 0; j--)
            if ((1 << i) - (1 << j) == x) return {i, j};
    return {-1, -1};
}

void solve() {
    int n; cin >> n;
    memset(cnt, 0, sizeof cnt); 
    int s= 0;
    
    for (int i = 0; i < n; i++)
        cin >> a[i], s += a[i];
    
    set<int> ck; 
    map<int, int> ls;
    
    //cout << nl;

    if (s % n) {
        cout << "NO" << nl;
        return;
    } else {
        s /= n;
        for (int i = 0; i < n; i++) {
            int diff = a[i] - s;
            if (diff == 0) continue;
            pi x = p2(abs(diff));
            
            if (x.ff == x.ss + 1) { ck.insert(abs(diff)), ls[diff]++; continue; }

            if (x.ff == -1) { cout << "NO" << nl; return; }
            if (diff < 0) swap(x.ff, x.ss);
    //        cout << x.ff << " : " << x.ss << nl;
            cnt[x.ff]++, cnt[x.ss]--;
        }
    }
   
    //cout << nl;

    vector<int> al;
    for (int c : ck) al.push_back(c);
    
    sort(al.begin(), al.end(), [](const int & a, const int & b) -> bool {
        return abs(a) > abs(b);
    });
    
    //cout << nl;
    
    //for (int i = 0; i < 30; i++)
    //    cout << cnt[i] << nl[i == 29];
    //
    //cout << nl;

    for (int c : al) {
        //cout << c << nl;
        int b = log2(c); 
        
        int n = ls[-c], p = ls[c];
        //cout << n << " " << p << " : " << cnt[b + 1] << nl;

        if (cnt[b + 1] > 0 && cnt[b + 1] > n) {
            cout << "NO" << nl;
            return;
        } else if (cnt[b + 1] > 0) n -= cnt[b + 1], cnt[b] += cnt[b + 1], cnt[b + 1] = 0;
        else if (cnt[b + 1] < 0 && -cnt[b + 1] > p) {
            cout << "NO" << nl;
            return;
        } else if (cnt[b + 1] < 0) p += cnt[b + 1], cnt[b] += cnt[b + 1], cnt[b + 1] = 0;
    
        //cout << n << " : " << p << nl;


        cnt[b] += (p - n);

 
        //for (int i = 0; i < 30; i++)
        //    cout << cnt[i] << nl[i == 29];
    

        //cout << nl;
    }
    
 
    //for (int i = 0; i < 30; i++)
    //    cout << cnt[i] << nl[i == 29];

    int yes = 1;
    for (int i = 0; i < 40; i++)
        yes &= !cnt[i];

    cout << (yes ? "YES" : "NO") << nl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t; cin >> t;
    while (t--)
        solve();
}
