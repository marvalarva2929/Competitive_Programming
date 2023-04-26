using namespace std;
#include <bits/stdc++.h>
#define int long long
#define nl '\n'
#define no "no"
#define yes "yes"
#define print(x, y, z) for (int i = y; i <= z; i++) {cout << x[i] << " ";} cout << nl;
bool grid[60][60];
bool vis[60][60];
vector<pair<int, int>> comp[2510];
int n, m;

const int dx[3] = {-1, 0, 1}, dy[3] = {-1, 0, 1};

bool formsL(vector<pair<int, int>> check) {
    if (check.size() != 3)
        return false;
    int mnx = 60, mny = 60;
    vector<pair<int, int>> loc = check;
    bool m_grid[2][2] = {};
    for (auto p : loc)
        mnx = min(mnx, p.first),
        mny = min(mny, p.second);
    for (auto & p : loc)
        p.first -= mnx,
        p.second -= mny;

    for (auto p : loc)
        if (p.first > 1 || p.second > 1)
            return false;
        else m_grid[p.first][p.second] = true;

    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            if (m_grid[(i + 1)%2][(j + 1)%2] && m_grid[i][(j + 1)%2] && m_grid[(i + 1)%2][j])
                return true;
    return false;
}

void dfs(int x, int y, int t) {   
    if (vis[x][y]) return;
    vis[x][y] = true;
    comp[t].push_back({x, y});
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++) {
            int nx = x + dx[i];
            int ny = y + dy[j];
            // cout << nx << " " << ny << nl;
            if (nx < n && ny < m && nx >= 0 && ny >= 0 && !vis[nx][ny] && grid[nx][ny])
                dfs(nx, ny, t);
        }
}

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

void solve() {
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            grid[i][j] = 0;
            vis[i][j] = false;
        }
    for (int i = 1; i < 2510; i++)
        comp[i] = vector<pair<int, int>>();
    
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            char c; cin >> c;
            grid[i][j] = (c == '*');
        }

    int comps = 1;

    for (int i = 0; i < n; i++) 
        for (int j = 0; j < m; j++)
            if (grid[i][j] && !vis[i][j]) 
                dfs(i, j, comps++);
    
    for (int i = 1; i < comps; i++) 
        if (!formsL(comp[i])) {
            cout << no << nl;
            return;
        }
    cout << yes << nl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t; cin >> t;
    while (t--)
        solve();
}