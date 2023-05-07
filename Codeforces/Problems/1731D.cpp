using namespace std;
#include <bits/stdc++.h>
#define int long long
#define nl '\n'
#define no "no"
#define yes "yes"
#define print(x, y, z) for (int i = y; i <= z; i++) {cout << x[i] << " ";} cout << nl;
#define MAX (int)1e6 + 10
vector<int> grid[MAX];
int n, m;

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

bool check(int x) {
    vector<vector<int>> c_grid(n, vector<int>(m, 0));
    vector<vector<int>> ps(n + 1, vector<int>(m + 1, 0));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            c_grid[i][j] = (grid[i][j] >= x),
            ps[i + 1][j + 1] += c_grid[i][j];

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            ps[i][j] += ps[i - 1][j] + ps[i][j - 1] - ps[i - 1][j - 1];

    for (int i = 1; i <= (n - x + 1); i++)
        for (int j = 1; j <= (m - x + 1); j++)
            if (ps[i + x - 1][j + x - 1] - ps[i + x - 1][j - 1] - ps[i - 1][j + x - 1] + ps[i - 1][j - 1] == (x * x))
                return true;
    
    return false;
}

void solve() {
    cin >> n >> m;
    fill(grid, grid + n + 1, vector<int>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> grid[i][j];

    int l = 1, r = min(n, m) + 1;
    while (r - l > 1) {
        int m = (l + r) >> 1;
        if (check(m)) 
            l = m;
        else r = m;
    }
    cout << l << nl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t; cin >> t;
    while (t--)
        solve();
}