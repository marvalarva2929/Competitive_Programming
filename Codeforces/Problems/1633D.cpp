using namespace std;
#include <bits/stdc++.h>    
#define int long long
#define nl '\n'
#define MAX (int)1e3 + 10
int d[(int)1e6 + 10];

void solve() {
    int n, k; cin >> n >> k;
    int b[n + 1] = {}, c[n + 1] = {};

    for (int i = 1; i <= n; i++)
        cin >> b[i];
    for (int i = 1; i <= n; i++)
        cin >> c[i];

    for (int & i : b) 
        i = d[i];

    // for (int i : b)
    //     cout << i << " ";
    // cout << nl;

    k = min(k, 12 * n + 10);

    int dp[n + 1][k + 1] = {};

    for (int i = 1; i <= n; i++)
        for (int j = 0; j <= k; j++) 
            if (j >= b[i])
                dp[i][j] = max(dp[i - 1][j - b[i]] + c[i], dp[i - 1][j]);
            else dp[i][j] = dp[i - 1][j];

    cout << dp[n][k] << nl;
    
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t; cin >> t;

    iota(d + 1, d + MAX, 0);

    for (int i = 2; i < MAX; i++)
        for (int j = 1; j <= i; j++)
            d[i + (i / j)] = min(d[i + (i / j)], d[i] + 1);

    while (t--)
        solve();
}