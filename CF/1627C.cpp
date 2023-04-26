using namespace std;
#include <bits/stdc++.h>
#define int long long
#define nl '\n'
#define MAX (int)1e5 + 10
#define pi pair<long, long>
#define vpi vector<pi>
#define vi vector<int>
vi adj[MAX];
map<pi, bool> w;

void dfs(vector<bool> & vis, int i, int f, int p) { // the curr index, the last index, and the value of the path visited before
    vis[i] = true;
    w[{f, i}] = w[{i, f}] = !p;
    for (int x : adj[i])
        if (!vis[x])
            dfs(vis, x, i, !p);
}

void solve() {
    int n; cin >> n;
    fill(adj, adj + n + 1, vi());
    vpi edges;

    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        edges.push_back({u, v});
        adj[u].push_back(v), adj[v].push_back(u);
    }

    int s = 0;

    for (int i = 1; i <= n; i++) 
        if (adj[i].size() > 2) {
            cout << -1 << nl;
            return;
        } else if (adj[i].size() == 1) s = i;

    vector<bool> vis(n + 1, false);
    dfs(vis, s, s, 0);

    for (auto edge : edges)
        cout << (w[edge] ? 2 : 11) << " ";
    cout << nl;    
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t; cin >> t;
    while (t--)
        solve();
}