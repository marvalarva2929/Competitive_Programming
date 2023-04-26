using namespace std;
#include <bits/stdc++.h>
#define nl '\n'
#define int long long

void solve() {
    int n, m; cin >> n >> m;
    int mn[n + 2] = {};
    fill(mn, mn + n + 1, n);

    for (int i = 0; i < m; i++) {
        int x, y; cin >> x >> y;
        if (x > y)
            swap(x, y);
        mn[x] = min(mn[x], y - 1);
    }

    // for (int i = 1; i <= n; i++)
    //     cout << mn[i] << " ";
    // cout << nl;

    // cout << nl;
    for (int i = n - 1; i; i--)
        mn[i] = min(mn[i], mn[i + 1]);

    int ans = n;
    for (int i = 1; i < n; i++) {
        // cout << i << " " << mn[i] << nl;
        ans += mn[i] - i;
    }
    cout << ans << nl;
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    int t; cin >> t;
    while (t--)
        solve();
}