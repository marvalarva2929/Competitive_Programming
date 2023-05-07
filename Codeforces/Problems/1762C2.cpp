using namespace std;
#include <bits/stdc++.h>
#define nl '\n'
#define int long long
#define MAX (int)1e6 + 10

void solve() {
    // cout << 'a' << nl;
    int n; cin >> n;
    int a[n] = {};
    for (int i = 0; i < n; i++)
        cin >> a[i];

    unordered_map<int, int> dp;

    for (int i : a) 
        dp[i + 1] = max(dp[i + 1], dp[i] + 1), dp[i] = max(dp[i], dp[i - 1] + 1);

    int ans = 0;
    for (int i : a)
        ans = max(ans, max(dp[i], dp[i + 1]));

    cout << ans << nl; 
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    int t; cin >> t;
    while(t--)
        solve();
}