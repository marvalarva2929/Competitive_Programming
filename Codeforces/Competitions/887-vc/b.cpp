#include <bits/stdc++.h>
#define int long long
#define pi pair<int, int>
#define nl " \n"
#define ff first
#define ss second

using namespace std;

void solve() {
    int n, k; cin >> n >> k;
    int ans = 0;
    
    for (int i = 0; i <= n; i++) {
        int len = 0;
        int cur = i;
        int pr = n;
        
        while (cur <= pr && cur >= 0) {
            len++;
            int ncur = pr - cur;
            pr = cur;
            cur = ncur;
        }
        ++len; 
        //cout << i << " : " << len << nl;

        ans += len >= k;
    }    

    cout << ans << nl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t; cin >> t;
    while (t--)
        solve();
}
