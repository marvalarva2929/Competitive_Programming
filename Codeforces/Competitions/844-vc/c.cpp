#include <bits/stdc++.h>
#define int long long
#define nl " \n"
#define pi pair<int, int>
#define ff first
#define ss second

using namespace std;
const int mxn = 2e5;
int a[mxn];
int dp[mxn][2]; // i, used > 1, parity

void solve() {
    int n; cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    
    dp[0][0] = 0;
    dp[0][1] = a[0];
    
    if (n > 1)
        dp[1][0] = 0,
        dp[1][1] = a[1];

    for (int i = 2; i < n; i++) {
        dp[i][0] = max(dp[i - 1][0], dp[i - 2][0]);
        dp[i][1] = max({dp[i - 2][0] + a[i], dp[i - 2][1] + a[i], dp[i - 2][1]});
    }   

    cout << max(dp[n - 1][1], (n > 1 ? dp[n - 2][1] : LLONG_MIN)) << nl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t; cin >> t;
    while (t--)
        solve();
}
