#include <bits/stdc++.h>
#define int long long
#define pi pair<int, int>
#define ff first
#define ss second
#define nl " \n"

using namespace std;

void solve() {
    int n, m; cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));

    if (m == 1) {
        cout << 0 << nl;
    } else if (n < m - 1) cout << n + 1 << nl;
    else cout << m << nl;

    int s = max((int)0, m - 1 - n);
    
    for (int i = 0; i < min(n, m - 1); i++)
        for (int j = 0; j < m; j++) {
            int d = (j + s + i + 1) % m;
            a[i][d] = j;     
        }
    
    for (int i = m - 1; i < n; i++)
        for (int j = 0; j < m; j++)
            a[i][j] = (j + 1) % m;
    
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cout << a[i][j] << nl[j == m - 1];
    
    
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t; cin >> t;
    while (t--)
        solve();
}
