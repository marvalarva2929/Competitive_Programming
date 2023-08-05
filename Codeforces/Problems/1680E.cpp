#include <bits/stdc++.h>
#define int long long
#define nl " \n"
#define pi pair<int, int>
#define ff first
#define ss second

using namespace std;
const int mxn = 2e5;
int a[mxn][2];

bool bet(pi a, pi b) {
    return ((a.ff >= b.ff) == (a.ss <= b.ss)) || ((a.ff <= b.ss && a.ff >= b.ff) || (a.ss >= b.ff && a.ss <= b.ss));
}

void solve(int t) {
    int n; cin >> n;
        
    for (int j = 0; j < 2; j++) 
        for (int i = 0; i < n; i++) {
            char c; cin >> c;
            a[i][j] = (c == '*');
        }
    
    pi bo = {INT_MAX, -1};
    
    for (int j = 0; j < 2; j++)
        for (int i = 0; i < n; i++)
            if (a[i][j]) 
                bo.ff = min(bo.ff, i),
                bo.ss = max(bo.ss, i);
    
    vector<vector<int>> dp(n, vector<int>(2, INT_MAX));
    
    dp[bo.ff][0] = a[bo.ff][1];
    dp[bo.ff][1] = a[bo.ff][0];
    

    for (int i = bo.ff; i < bo.ss; i++) {
        for (int j = 0; j < 2; j++) {
            dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + a[i + 1][!j] + 1);
            dp[i + 1][j] = min(dp[i + 1][j], dp[i][!j] + 2);
        }
    }
    
    cout << min(dp[bo.ss][0], dp[bo.ss][1]) << nl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t; cin >> t;
    for (int i = 1; i <= t; i++)
        solve(i);
}
