using namespace std;
#include <bits/stdc++.h>
#define int long long
#define nl '\n'

void solve(int t) {
    int n; cin >> n;
    int a[n + 1] = {}, b[n + 1] = {};
    int ans[n + 1][2] = {}; // 0 for min, 1 for max
    int mn = INT_MAX;



    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        cin >> b[i];

    if (n == 1) {
        cout << abs(a[1] - b[1]) << nl << abs(a[1] - b[1]) << nl;
        return;
    }

    int lst = n;
    for (int i = n; i; i--) {
        ans[i][1] = b[lst] - a[i];
        if (b[i - 1] < a[i])
            lst = i - 1;
    }

    for (int i = 1; i <= n; i++)
        ans[i][0] = abs(*lower_bound(b + 1, b + n + 1, a[i]) - a[i]);

    for (int i = 0; i < 2; i++) {
        for (int j = 1; j <= n; j++)
            cout << ans[j][i] << " ";
        cout << nl;
    }
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t; cin >> t;
    for (int i = 1; i <= t; i++)
        solve(i);
}