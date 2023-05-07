using namespace std;
#include <bits/stdc++.h>
#include <string.h>
typedef long long ll;
typedef vector<int> vi;
typedef vector<pair<int,int>> vpi;
#define pb push_back
#define int long long
#define nl '\n'
#define rsz resize
#define sz(x) int(x.size())
#define all(x) begin(x), end(x)
#define f first
#define s second
#define print(x, y, z) for (int i = y; i <= z; i++) {cout << x[i] << " ";} cout << nl;
#define MAX 100
vector<char> temp(MAX);
vector<vector<char>> grid(MAX, temp);
const int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};

bool isAdjTo(int x, int y, int n, int m, char c) {
    for (int d = 0; d < 4; d++) {
        int nx = dx[d] + x, ny = dy[d] + y;
        if (nx >= 0 && ny >= 0 && ny < m && nx < n) {
            if (grid[nx][ny] == c) 
                return true;
        }
    }
    return false;
}

void dfs(int x, int y, int n, int m, map<pair<int, int>, bool> &visited) {
    // cout << x << ": " << y << "- " << grid[x][y] << nl;
    if (grid[x][y] == '#') return;
    if (visited[{x, y}]) return;
        visited[{x, y}] = true;
        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d], ny = y + dy[d];
            if (nx >= 0 && ny >= 0 && ny < m && nx < n) {
                if (!visited[{nx, ny}]) {
                    dfs(nx, ny, n, m, visited);
                }
            }
        }
     
    
}

void solve() {
    int n, m;
    cin >> n >> m;
    int Gs = 0;
        
    for (int i = 0; i <= m; i++) {
        grid[n].clear();
    }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) 
            cin >> grid[i][j];


    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (grid[i][j] == 'B') {
                for (int d = 0; d < 4; d++) {
                    int nx = i + dx[d], ny = j + dy[d];
                    if (nx >= 0 && ny >= 0 && grid[nx][ny] == '.')
                        grid[nx][ny] = '#';
                }
            } else if (grid[i][j] == 'G') {
                if (isAdjTo(i, j, n, m, 'B')) {
                    cout << "No" << nl;
                    return;
                }
            }
            
    // for (int i = 0; i < n; i++)
    //     for (int j = 0; j < m; j++)
    //         cout << i << ", " << j << ": " << grid[i][j] << nl;

    
    map<pair<int, int>, bool> visited;
    // cout << Gs << nl;
    dfs(n - 1, m - 1, n, m, visited);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (!visited[{i, j}] && grid[i][j] == 'G') {
                cout << "no" << nl;
                return;
            } 
            

    cout << "yes" << nl;

}

int32_t main() {
    int t;
    cin >> t;
    while (t--)
        solve();
} 