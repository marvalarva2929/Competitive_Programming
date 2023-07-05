using namespace std;
#include <bits/stdc++.h>
#define int long long
#define nl '\n'
#define no "no"
#define yes "yes"
#define print(x, y, z) for (int i = y; i <= z; i++) {cout << x[i] << " ";} cout << nl;

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

const int mxn = 5e5;
const int MOD = 998244353;
int a[mxn], dp[mxn + 1], dp1[mxn + 1];

void solve() {
    int n; cin >> n;
    fill(dp, dp + n + 1, 0);
    fill(dp1, dp1 + n + 1, 0);

    for (int i = 0; i < n; i++)
        cin >> a[i];

    int ans = 0;
    dp[0] = 1;
    for (int i = 0; i < n; i++) {
        if (a[i] > 0) dp1[a[i] - 1] = (dp1[a[i] - 1] % MOD + dp1[a[i] - 1]) % MOD + (dp[a[i] - 1] % MOD) % MOD;
        dp[a[i] + 1] = dp[a[i] + 1] + dp[a[i] + 1] % MOD;
        dp[a[i] + 1] = dp[a[i] + 1] % MOD + dp[a[i]] % MOD;
        dp1[a[i] + 1] = dp1[a[i] + 1] % MOD + dp1[a[i] + 1] + MOD;

        if (a[i] > 0) dp1[a[i] - 1] %= MOD;
        dp[a[i] + 1] %= MOD;
        dp1[a[i] + 1] %= MOD;
    }

    for (int i = 0; i <= n; i++)
        ans = (ans + dp[i]) % MOD + dp1[i] % MOD;

    cout << (ans % MOD + (MOD - 1) % MOD) % MOD << "\n";
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t; cin >> t;
    while (t--)
        solve();
}