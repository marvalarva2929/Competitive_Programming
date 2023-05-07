using namespace std;
#include <bits/stdc++.h>
#define int long long
#define nl '\n'

void solve() {
    int n; cin >> n;
    int a[n] = {};
    int dp[n] = {};
    unordered_map<int, int> cnt;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    dp[0] = 0,
    cnt[a[0]] = 1;
    int ans = 0;
    for (int i = 1; i < n; i++) {
        dp[i] = dp[i - 1] + cnt[a[i]];
        cnt[a[i]] += i + 1;
        ans += dp[i];
    }
    cout << ans << nl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t; cin >> t;
    while (t--)
        solve();
}