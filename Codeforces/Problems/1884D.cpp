#include <bits/stdc++.h>
#define int long long
#define nl " \n"
#define pi pair<int, int>
#define ff first
#define ss second

using namespace std;
const int mxn = 1e6;
int a[mxn], can[mxn+1], dp[mxn+1], cnt[mxn + 1];

void solve() {
    int n; cin >> n;
    fill(can, can + n + 1, 0);
    fill(dp, dp + n + 1, 0);
    fill(cnt, cnt + n + 1, 0);

    for (int i = 0; i < n; i++)
        cin >> a[i], cnt[a[i]]++;

    sort(a, a + n);
    for (int i = 0; i < n; i++)
        if (can[a[i]]) continue;
        else for (int j = a[i]; j <= n; j += a[i])
            can[j] = 1;

    for (int i = n; i >= 1; i--) {
        int cn = 0;
        for (int j = i; j <= n; j += i) cn += cnt[j], dp[i] -= dp[j];

        dp[i] += (cn * (cn - 1)) / 2;
    }
    
    int ans = 0;
    for (int i = 1; i <= n; i++)
        if (!can[i]) ans += dp[i]; 
    
    cout << ans << nl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t; cin >> t;
    while (t--)
        solve();
}
