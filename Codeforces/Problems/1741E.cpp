using namespace std;
#include <bits/stdc++.h>
#define int long long
#define nl '\n'
#define MAX (int)2e5 + 10
int a[MAX];
int dp[MAX]; 
void solve() {
    int n; cin >> n;
    fill(dp, dp + n + 1, 0);

    for (int i = 1; i <= n; i++)
        cin >> a[i];
    
    if (n == 1) {
        cout << "NO" << nl;
        return;
    }

    dp[0] = true;
    if (a[1] < n) dp[a[1] + 1] = true;

    for (int i = 2; i <= n; i++) {
        if (a[i] <= i) {
            dp[i] |= dp[i - a[i] - 1];
            // if (dp[i - a[i] - 1]) cout << " index " << i << " goes back to " << i - a[i] << nl;
            // else cout << "index " << i <<" did not go back to " << i - a[i] << nl;
        }
        if (i + a[i] <= n && dp[i - 1]) {
            dp[i + a[i]] = true;
            // cout << " index " << i << " ends at " << i + a[i] << nl;
        }
    }


    cout << (dp[n] ? "YES" : "NO") << nl;

}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t; cin >> t;
    while (t--)
        solve();
}