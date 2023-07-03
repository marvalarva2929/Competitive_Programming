#include <bits/stdc++.h>
#define int long long
#define nl " \n"
#define pi pair<int, int>
#define ff first
#define ss second

using namespace std;
const int mxn = 1000;
int a[mxn][mxn];

void solve() {
    int n, m; cin >> n >> m;
    
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            a[i][j] = 0;
    
    a[0][0] = m + 1;
    a[n/2][0] = 1;
    

    for (int i = 1; i < n; i++)
        if (!a[i][0]) a[i][0] = a[i - 1][0] + (2 * m);
    
    for (int i = 0; i < n; i++) {
        for (int j = 1; j < m; j++)
            a[i][j] = a[i][j -1] + 1;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            cout << a[i][j] << " ";
        cout << nl; 
    }


}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t; 
    cin >> t;
    while (t--)
        solve();
}
