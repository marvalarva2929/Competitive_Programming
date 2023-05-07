using namespace std;
#include <bits/stdc++.h>
#define int long long
#define nl '\n'

void solve() {
    int n; cin >> n;
    int a[n + 1] = {};
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    int cmp[n + 1] = {};
    int comp = 0;

    for (int i = 1; i <= n; i++) {
        if (!cmp[i]) {
            comp++;
            int j = i;
            while (!cmp[j]) {
                cmp[j] = comp;
                j = a[j]; 
            }
        }
    }

    int ans = n - comp + 1;
    for (int i = 2; i <= n; i++)
        if (cmp[i - 1] == cmp[i]) {
            ans = n - comp - 1;
            break;
        }

    cout << ans << nl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t; cin >> t;
    while (t--)
        solve();
}