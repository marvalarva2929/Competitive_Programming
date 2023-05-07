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
#define s second
#define print(x, y, z) for (int i = y; i <= z; i++) {cout << x[i] << " ";} cout << nl;
#define MOD (int)1e8
int dp[101][101][11][11]; //number of consec footmen, number of consec horses, number of consecutive footmen and number of consecutive horses

int32_t main() {
    int n1, n2, k1, k2;
    cin >> n1 >> n2 >> k1 >> k2;
    int n = n1 + n2;

        for (int f = 0; f <= n1; f++) {
            for (int h = 0; h <= n2; h++) {
                for (int kf = 0; kf <= k1; kf++) {
                    for (int kh = 0; kh <= k2; kh++) {
                        if (f + h == 0) { dp[f][h][kf][kh] = 1; continue; }
                        int foot = (kf > 0 && f > 0 ? dp[f - 1][h][kf - 1][k2] : 0);
                        int horse = (kh > 0 && h > 0 ? dp[f][h - 1][k1][kh - 1] : 0);
                        dp[f][h][kf][kh] = ((foot % MOD) + (horse % MOD)) % MOD;

                        // dp[i][h][f][kf][kh] = foot + horse;
                    }
                }
            }
        }
    
    cout << dp[n1][n2][k1][k2] % MOD << nl;
} 