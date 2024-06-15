#include <bits/stdc++.h>
#define int long long
#define nl " \n"
#define pi pair<int, int>
#define ff first
#define ss second

using namespace std;

void solve() {

    vector<int> dp, lst, rq;
    vector<pi> ops;
     
    int n, q; cin >> n >> q;
    int c = 0; 

    for (int i = 0; i < n; i++) { 
        int t, x; cin >> t >> x;
        ops.emplace_back(t, x);
    }
    
    int mx = 0;
    for (int i = 0; i < q; i++) {
        int t; cin >> t;
        rq.push_back(t);
        mx = max(mx, t); 
    }
    
    dp.push_back(0);
    
    for (auto [t, x] : ops) {
        if (dp.back() > mx) break;
        if (t == 1) {
            dp.push_back(dp.back() + 1);
            lst.push_back(x);
        } else {
            int mult = min(mx / dp.back(), x);
            dp.push_back(dp.back() * (++mult));
            lst.push_back(lst.back()); 
        }
    }
    
    for (int x : rq) {
        auto i = lower_bound(dp.begin(), dp.end(), x); 
        int idx = i - dp.begin(), l = *i; 
        
        bool c = 0;
        while (l != x) {
            x %= dp[idx - 1]; 
            if (x == 0) {
                cout << lst[idx - 1] << " "; c = 1;
                break;
            } 
            i = lower_bound(dp.begin(), dp.end(), x); 
            idx = i - dp.begin(), l = *i; 
        }
        
        if (!c) cout << lst[idx - 1] << " ";
    }
    cout << nl;

}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t; cin >> t;
    while (t--)
        solve();
}
