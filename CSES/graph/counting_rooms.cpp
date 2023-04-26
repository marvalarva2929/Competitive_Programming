using namespace std;
#include <bits/stdc++.h>
#define int long long
#define nl '\n'
bool grid[1000][1000];
bool vis[1000][1000];
int n, m;
const int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, -1, 0, 1};

void dfs(int x, int y) {
    vis[x][y] = true;

    for (int i = 0; i < 4; i++) {
        if ((x + dx[i] < n && y + dy[i] < m && x + dx[i] >= 0 && y + dy[i] >= 0) && !vis[x + dx[i]][y + dy[i]])
            if (grid[x + dx[i]][y + dy[i]])   
                dfs(x + dx[i], y + dy[i]);
    }
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            { char c; cin >> c; grid[i][j] = c == '.'; }

    int ans = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (!vis[i][j] && grid[i][j]) 
                dfs(i, j),
                ans++;

    cout << ans << nl;
}