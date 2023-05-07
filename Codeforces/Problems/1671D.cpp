using namespace std;
#include <bits/stdc++.h>
#define int long long
#define nl '\n'

void solve() {
    int n, x; cin >> n >> x;
    int a[n] = {};
    int ans = 0, mx = 0, mn = LLONG_MAX;

    for (int i = 0; i < n; i++)
        cin >> a[i], 
        mx = max(mx, a[i]),
        mn = min(mn, a[i]);

    for (int i = 1; i < n; i++)
        ans += abs(a[i] - a[i - 1]);

    if (mn > 1) {
        int mn_ans = min(abs(1 - a[0]), abs(1 - a[n - 1]));
        for (int i = 1; i < n; i++)
            mn_ans = min(mn_ans, abs(1 - a[i - 1]) + abs(1 - a[i]));

        // if (mn > x) {
            // ans += mn_ans;
        // } else {
            ans += min((mn - 1) * 2, mn_ans);
        // }
    } 

    if (mx < x) {

        int mn_ans = min(abs(x - a[0]), abs(x - a[n - 1]));
        for (int i = 1; i < n; i++)
            mn_ans = min(mn_ans, abs(x - a[i - 1]) + abs(x - a[i]));

        ans += min(mn_ans, (x - mx) * 2);
    }

    cout << ans << nl;
    return;
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t; cin >> t;
    while (t--)
        solve();
}