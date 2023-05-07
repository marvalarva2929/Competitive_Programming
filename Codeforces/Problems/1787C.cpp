using namespace std;
#include <bits/stdc++.h>
#define int long long
#define nl '\n'
#define MAX (int)2e5 + 10
#define min(x, y) min((long long)x, (long long)y)
#define max(x, y) max((long long)x, (long long)y)

int x[MAX][2]; // 0 for min, 1 for max
int dp[MAX][2];

void solve() {
    int n, s; cin >> n >> s;
    int a[n] = {};
    for (int i = 0; i < n; i++)
        cin >> a[i];

    for (int i = 0; i < n; i++) {
        int c = min(a[i], s),
            b = max(0, (int)a[i] - c);

        x[i][1] = max(c, b);
        x[i][0] = min(c, b);
    }

    dp[1][1] = (a[0] * x[1][1]);
    dp[1][0] = (a[0] * x[1][0]);

    // cout << dp[1][1] << " " << dp[1][0] << nl;

    for (int i = 2; i < n - 1; i++) {
        for (int m = 0; m < 2; m++)
            dp[i][m] = min((x[i][m] * x[i - 1][m]) + dp[i - 1][!m], ((x[i][m] * x[i - 1][!m]) + dp[i - 1][m]));
        // cout << i << " : " << dp[i][1] << " " << dp[i][0] << nl;
    }
    cout << min(dp[n - 2][1] + (a[n - 1] * x[n - 2][0]), dp[n - 2][0] + (a[n - 1] * x[n - 2][1])) << nl;
    
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t; cin >> t;
    while (t--)
        solve();
}