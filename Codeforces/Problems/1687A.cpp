using namespace std;
#include <bits/stdc++.h>
#define int long long
#define nl '\n'

void solve() {
    int n, k; cin >> n >> k;
    int a[n + 1] = {};
    for (int i = 1; i <= n; i++)
        cin >> a[i], a[i] += a[i - 1];

    if (k < n) {
        int mx = 0;
        for (int i = 0; i <= n - k; i++)
            mx = max(mx, a[i + k] - a[i]);
        cout << mx + ((k - 1) * k)/2 << nl;
        return;
    } else {
        cout << a[n] + (k * n) - ((n + 1) * n)/2 << nl;
    }
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t; cin >> t;
    while (t--)
        solve();
}