using namespace std;
#include <bits/stdc++.h>
#define int long long
#define nl '\n'

const int mxn = (int)1e5 + 10;

vector<int> adj[mxn];
vector<int> comp[mxn];
bool vis[mxn];
int n, m;

void dfs(int x, int c) {
    vis[x] = true;
    comp[c].push_back(x);
    for (int next : adj[x]) 
        if (!vis[next])
            dfs(next, c);
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 0; i < m; i++) { 
        int to, from; cin >> to >> from;
        adj[to].push_back(from);
        adj[from].push_back(to);
    }

    int components = 0;
    for (int i = 1; i <= n; i++)
        if (!vis[i])
            dfs(i, ++components);
    
    cout << components - 1 << nl;
    for (int i = 1; i < components; i++)   
        cout << comp[i].front() << " " << comp[i + 1].front() << nl;
}