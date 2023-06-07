#include <bits/stdc++.h>
#define int long long
#define nl '\n'

using namespace std;

const int mxn = 5000, mxk = 5000;
int dp[mxn][mxn][2];
int a[mxn + 1];
int c[mxk + 1];
int h[mxk + 1];

void solve() {
    int n, k; cin >> n >> k;

    for (int i = 0; i < n; i++)
        cin >> a[i + 1];
    for (int i = 0; i < k; i++)
        cin >> c[i + 1];
    for (int i = 0; i < k; i++)
        cin >> h[i + 1];

    dp[0][0][0] = c[a[1]];
    dp[0][0][1] = c[a[1]]; 

    for (int i = 2; i <= n; i++) {
        for (int j = 0; j < i - 1; j++)
            for (int k = 0; k < 2; k++) {
                
                dp[1][j][k] = dp[0][j][k] + (a[i - 1] == a[i] ? h[a[i]] : c[a[i]]);
                
                if (dp[1][i - 1][k])
                    dp[1][i - 1][k] = min(dp[1][i - 1][k], dp[0][j][!k] + (a[j] == a[i] ? h[a[i]] : c[a[i]]));
                else dp[1][i - 1][k] = dp[0][j][!k] + (a[j] == a[i] ? h[a[i]] : c[a[i]]); 
            }
        
        for (int j = 0; j <= n; j++)
            for (int k = 0; k < 2; k++)
                dp[0][j][k] = dp[1][j][k],
                dp[1][j][k] = 0;
    }
    
    int ans = LLONG_MAX;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < 2; j++)
            ans = min(ans, dp[0][i][j]);

    cout << ans << nl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t; cin >> t;
    while (t--)
        solve();
}
