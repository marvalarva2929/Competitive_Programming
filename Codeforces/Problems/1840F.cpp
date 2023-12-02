#include <bits/stdc++.h>
#define int long long
#define nl " \n"
#define pi pair<int, int>
#define ff first
#define ss second

using namespace std;
const int mxn = 1e4;

void solve() {
    int n, m, r; cin >> n >> m >> r;
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(m + 1, vector<int>(r + 1, 0)));
    map<pi, bool> ch, cv;
    
    for (int i = 0; i < r; i++) {
        int t, d, c; cin >> t >> d >> c;
        if (d == 1) ch[{t, c}] = 1;
        else cv[{t, c}] = 1;
    }
    
    dp[0][0][0] = 1;
    
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            for (int k = 0; k <= r; k++) {
                int t = i + j + k;
                if (ch[{t, i}] || cv[{t, j}]) continue;
                
                if (i && dp[i - 1][j][k]) dp[i][j][k] = 1;
                if (j && dp[i][j - 1][k]) dp[i][j][k] = 1;
                if (k && dp[i][j][k - 1]) dp[i][j][k] = 1;
            }
        }
    }
    
    for (int i = 0; i <= r; i++) 
        if (dp[n][m][i]) {
            cout << n + m + i << nl;
            return;
        }
    
    cout << -1 << nl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t; cin >> t;
    while (t--)
        solve();
}
