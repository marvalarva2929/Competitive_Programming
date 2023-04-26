using namespace std;
#include <bits/stdc++.h>
#include <string.h>
typedef long long ll;
typedef vector<int> vi;
typedef vector<pair<int,int>> vpi;
#define pb push_back
#define int long long
#define nl '\n'
#define rsz resize
#define sz(x) int(x.size())
#define all(x) begin(x), end(x)
#define f first
#define s second
#define print(x, y, z) for (int i = y; i <= z; i++) {cout << x[i] << " ";} cout << nl;
int dp[51][51][4][2]; // x, y, turs, last direction: 0 left, 1 down
char grid[51][51];

const int dx[2] = {0, -1}, dy[2] = {-1, 0};

void solve() {
    int n, k;
    cin >> n >> k;

    memset(dp, 0, sizeof(dp));
    memset(grid, 0, sizeof(grid));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> grid[i][j];

    for (int i = 0; i <= k; i++)
        dp[0][0][i][0] = dp[0][0][i][1] = 1;

    int i = 0;
    while (i < n && grid[0][i] != 'H') {
        for (int j = 0; j <= k; j++)
            dp[0][i][j][1] = 1;
        i++;
    }

    i = 0;
    while (i < n && grid[i][0] != 'H') {
        for (int j = 0; j <= k; j++)
            dp[i][0][j][0] = 1;
        i++;
    }

    for (int x = 1; x < n; x++) {
        for (int y = 1; y < n; y++) {
            if (grid[x][y] == 'H') continue;
            for (int j = 1; j <= k; j++) {
                if (y > 0) {
                    dp[x][y][j][1] += dp[x][y - 1][j][1];
                    dp[x][y][j][1] += dp[x][y - 1][j - 1][0];
                }
                if (x > 0) {
                    dp[x][y][j][0] += dp[x - 1][y][j][0];
                    dp[x][y][j][0] += dp[x - 1][y][j - 1][1];
                }
                // cout << x << ": " << y << ": " << j << ": " << dp[x][y][j][0] << ": " << dp[x][y][j][1] << nl;
            }
            // cout << nl;
        }
    }
    cout << dp[n - 1][n - 1][k][1] + dp[n - 1][n - 1][k][0] << nl;
}

int32_t main() {
    int t; cin >> t;
    while (t--)
        solve();
} 