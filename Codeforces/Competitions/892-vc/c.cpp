#include <bits/stdc++.h>
#define int long long
#define nl " \n"
#define pi pair<int, int>
#define ff first
#define ss second

using namespace std;

void solve() {
    int n; cin >> n;
    int ans = 0;
    
    for (int i = 1; i <= n; i++)
        for (int j = i; j <= n; j++) {
            int mx = i * j;
            int cur = 0;
            bool no = false;

            vector<int> b(n + 1);
            stack<int> can;

            for (int k = n; k > 0; k--) {
                int x = min(n, mx / k); 
                for (int l = cur; l <= x; l++)
                    can.push(l);
                if (!can.size()) {
                    no = true;
                    break;
                }

                b[k] = can.top();
                can.pop();
                cur = x + 1; 
            }
            if (no) continue;

            int s = 0;
            for (int l = 1; l <= n; l++)
                s += b[l] * l;
                
            ans = max(ans, s - mx);
        }
    
    cout << ans << nl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t; cin >> t;
    while (t--)
        solve();
}
