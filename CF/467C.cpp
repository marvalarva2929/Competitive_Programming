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
#define MAX (int)5e3 + 10
#define max(x, y) max((long long)x, (long long)y)
int dp[MAX][MAX];
int a[MAX];
int psums[MAX];

int32_t main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n, m, k; cin >> n >> m >> k;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        psums[i] = psums[i - 1] + a[i];
    }



    for (int i = 1; i <= k; i++)
        for (int j = i * m; j <= n; j++) {
            dp[i][j] = max(dp[i][j - 1], dp[i - 1][j - m] + psums[j] - psums[j - m]);
        }

    cout << dp[k][n] << nl;

} 