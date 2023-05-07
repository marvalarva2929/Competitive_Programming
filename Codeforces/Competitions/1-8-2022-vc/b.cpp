using namespace std;
#include <bits/stdc++.h>
#define int long long
#define nl '\n'

void solve() {
    int nn; cin >> nn;
    int n = nn * nn;
    int a[n] = {};
    int iter = 0;
    int iter2 = n;

    for (int i = 0; i < n; i += 2)
        a[i] = ++iter;
    
    for (int i = 0; i < n && iter2 > iter; i++)
        if (!a[i])  
            a[i] = iter2--;

    vector<int> grid[nn];

    for (int i = 0; i < nn; i++)
        for (int j = i * nn; j < (i + 1) * nn; j++)
            grid[i].push_back(a[j]);
    
    for (int i = 1; i < nn; i += 2)
        reverse(grid[i].begin(), grid[i].end());

    for (int i = 0; i < nn; i++) {
        for (int j = 0; j < nn; j++)
            cout << grid[i][j] << " ";
        cout << nl;
    }

}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t; cin >> t;
    while (t--)
        solve();
}