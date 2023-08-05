#include <bits/stdc++.h>
#define int long long
#define nl " \n"
#define pi pair<int, int>
#define ff first
#define ss second

using namespace std;
const int mxn = 2e5;
int a[mxn][2];
int dp[mxn + 1][2];

void solve() {
    int n; cin >> n;
    
    for (int i = 0; i < n; i++)
        cin >> a[i][0];
    for (int i = 0; i < n; i++)
        cin >> a[i][1];
    
    dp[n][0] = dp[n][1] = 0;
    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j < 2; j++)
            dp[i][j] = max({dp[i + 1][j] - (i != 0), a[i][j], a[i][!j] - ((n - i - 1) * 2 + (i != 0))});
    }
    
    int cur = 0;
    int ans = INT_MAX;
    
    //for (int i = 0; i < n; i++)
    //    cout << dp[i][0] << " " << dp[i][1] << nl;
    
    for (int i = 0; i < n; i++) {
        int id = i % 2;
        ans = min(ans, max(cur, dp[i][id] - (i * 2 - (i != 0))));
    //    cout << i << " : " << cur << " " << dp[i][id] << " " << ans << nl;
        cur = max({cur, i == 0 ? INT_MIN : a[i][id] - (i * 2 - 1), a[i][!id] - (i * 2)});
    }
    
    cout << max((int)0, ans) + (2 * n - 1) << nl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t; cin >> t;
    while (t--)
        solve();
}
