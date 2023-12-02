#include <bits/stdc++.h>
#define int long long
#define nl " \n"
#define pi pair<int, int>
#define ff first
#define ss second

using namespace std;

void solve() {
    int n, m, k; cin >> n >> m >> k; 
    if (k < n + m - 2) { cout << "NO" << nl; return; }
    if ((k + n + m) % 2) { cout << "NO" << nl; return; }

    cout << "YES" << nl;
    vector<vector<char>> 
        b(n, vector<char>(m - 1)),
        c(n - 1, vector<char>(m));

    for (int j = 0; j < n; j++) 
        for (int i = 0; i < m - 1; i++)
            b[j][i] = 'R'; 
    
    for (int j = 0; j < n - 1; j++) 
        for (int i = 0; i < m; i++)
            c[j][i] = 'B'; 
    
    int l = 1;
 
    for (int i = (n + m - 2 == k ? 0 : 2); i < n - 1; i++)
        c[i][0] = ((l ^= 1) ? 'B' : 'R');   
    for (int i = 0; i < m - 1; i++)
        b[n - 1][i] = ((l ^= 1) ? 'B' : 'R');


    for (int i = 0; i < n; i++)
        for (int j = 0; j < m - 1; j++)
            cout << b[i][j] << nl[j == m - 2];

    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < m; j++)
            cout << c[i][j] << nl[j == m - 1];
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t; cin >> t;
    while (t--)
        solve();
}
