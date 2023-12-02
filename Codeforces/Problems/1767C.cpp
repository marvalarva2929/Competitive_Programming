#include <bits/stdc++.h>
#define int long long
#define nl " \n"
#define pi pair<int, int>
#define ff first
#define ss second

using namespace std;
const int mxn = 100, MOD = 998244353;
int dp[mxn + 1][mxn + 1];
vector<pi> cnst[mxn + 1];

bool check(int j, int i) {
    
    for (pi req : cnst[i])
        if (req.ff == 1 && req.ss <= j) return false;
        else if (req.ff == 2 && req.ss > j) return false;

    return true;
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);
    
    int n; cin >> n;
    bool ok = false;
    for (int i = 1; i <= n; i++) 
        for (int j = i; j <= n; j++) {
            int x; cin >> x;
            if (i == j && x > 1) {
                ok = true;
            }
            if (x) cnst[j].emplace_back(x, i);
    }
   
    if (ok) { cout << 0 << nl; return 0; }

    dp[1][0] = 2;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (check(j, i + 1))
                dp[i + 1][j] = dp[i + 1][j] +  dp[i][j] % MOD;
            if (check(i, i + 1))
                dp[i + 1][i] = dp[i + 1][i] + dp[i][j] % MOD;
        } 
    }

    int s = 0;
    for (int i = 0; i <= n; i++)
        s = s + dp[n][i] % MOD;

    cout << s % MOD << nl;;
}
