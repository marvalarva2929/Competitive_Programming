using namespace std;
#include <bits/stdc++.h>    
#define int long long
#define nl " \n"

int a[256][256];

void solve() {
    int n, m; cin >> n >> m;
    cout << (n * m) << nl;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cout << a[i][j] << nl[j + 1 == m];
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int cur = 0;

    for (int i = 0; i < (1 << 8); i++)
        for (int j = 0; j < (1 << 8); j++)
            a[i][j] = cur,
            a[i][j + 1] = cur + 1,
            a[i + 1][j] = cur + 2,
            a[i + 1][j + 1] = cur + 3,
            cur += 4;

    int t; cin >> t;
    while (t--)
        solve();
}