#include <bits/stdc++.h>
#define int long long
#define nl " \n"
#define pi pair<int, int>
#define ff first
#define ss second

using namespace std;
const int mxn = 2e5, MOD = 998244353;
int n, k;
int ans[mxn + 1], dp[mxn + 1];

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    cin >> n >> k;
    
    dp[0] = 1;
    for (int i = 0; i <= n - k; i += k++) {
        vector<int> sum(n + 1);
        for (int j = i; j <= n; j++) {
            int cur = dp[j];
            dp[j] = sum[j % k] % MOD;
            sum[j % k] = (sum[j % k] + cur) % MOD;
            ans[j] = (ans[j] + dp[j]) % MOD; 
        }
    }
    
    for (int i = 1; i <= n; i++)
        cout << ans[i] << nl[i == n];
}
