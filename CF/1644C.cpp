using namespace std;
#include <bits/stdc++.h>
#define int long long
#define nl '\n'

void solve() {
    int n, x; cin >> n >> x;
    int a[n + 1] = {};
    int p[n + 1] = {};
    int ans[n + 1] = {};

    for (int i = 0; i < n; i++)
        cin >> a[i], p[i + 1] = p[i] + a[i] + x;


    for (int i = 1; i <= n; i++)    
        for (int j = i; j <= n; j++)
            ans[j - i + 1] = max(ans[j - i + 1], p[j] - p[i - 1]);

    // while (true) {
    //     int x; cin >> x;
    //     cout << ans[x] << nl;
    // }

    for (int i = n - 1; i >= 0; i--)
        ans[i] = max(ans[i], ans[i + 1] - x);

    for (int i = 1; i <= n; i++)
        ans[i] = max(ans[i - 1], ans[i]);

    for (int i = 0; i <= n; i++) 
        cout << ans[i] << " ";
    cout << nl;
}

signed main() {
    // cin.tie(0)->sync_with_stdio(false);

    int t; cin >> t;
    while (t--)
        solve();
}