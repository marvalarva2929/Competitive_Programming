using namespace std;
#include <bits/stdc++.h>
#define int long long
#define nl '\n'
int a[1510][1510];
int grid[1510][1510];
int n;

int firstcal() {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (a[i][j]) grid[i][j + 1] += grid[i][j];
            else grid[i + 1][j] += grid[i][j]; 

    int ret = 0;
    for (int i = 0; i < n; i++)
        ret += (a[n][i] * grid[n][i]) + (a[i][n] * grid[i][n]);
    
    return ret;
}

int recalc(int aa, int bb) {
    int x = aa, y = bb;
    int sub = grid[x][y];

    while (x <= n && y <= n) {
        if (a[x][y]) y++;
        else x++;
        grid[x][y] -= sub;
        if (x == n || y == n) break;
    }
    x = aa, y = bb;
    a[x][y] = !a[x][y];

    while (x <= n && y <= n) {
        if (a[x][y]) y++;
        else x++;
        grid[x][y] += sub;
        if (x == n || y == n) break;
    }

    int ret = 0;
    for (int i = 0; i < n; i++)
        ret += (a[n][i] * grid[n][i]) + (a[i][n] * grid[i][n]);
    
    return ret;
}   

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            grid[i][j] = 1;
        
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            char c; cin >> c;
            a[i][j] = (c == 'R'); // 1 for R, 0 for D
        }
        cin >> a[i][n];
    }
    for (int i = 0; i < n; i++)
        cin >> a[n][i];

    cout << firstcal() << nl;
    int q; cin >> q;
    for (int i = 0; i < q; i++) {
        int x, y; cin >> x >> y;
        --x, --y;
        cout << recalc(x, y) << nl;
    }
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t = 1;
    while (t--)
        solve();
}