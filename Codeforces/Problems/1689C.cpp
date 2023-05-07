using namespace std;
#include <bits/stdc++.h>
#define int long long
#define nl '\n'
#define MAX (int)3e5 + 10
#define pi pair<int, int>

int sz[MAX];
vector<int> adj[MAX];
int dp[MAX];

int dfs(int x, int depth, int prev, vector<bool> & vis) {
    vis[x] = true;
    int size = 1;
    vector<int> children;

    for (int i : adj[x])
        if (!vis[i])
            size += dfs(i, depth + 1, x, vis), children.push_back(i);

    if (children.size() == 1)
        dp[x] = sz[children[0]];
    else if (children.size() == 2)
        dp[x] = max(dp[children[1]] + sz[children[0]], dp[children[0]] + sz[children[1]]);
    

    sz[x] = size - 1;
    return size;
}

void solve() {
    int n; cin >> n;

    fill(adj, adj + n + 1, vector<int>());
    fill(sz, sz + n + 1, 0);
    fill(dp, dp + n + 1, 0);

    vector<bool> vis(n + 1, 0);
    for (int i = 0; i < n - 1; i++) {
        int to, fro; cin >> to >> fro;
        adj[to].push_back(fro);
        adj[fro].push_back(to);
    }

    dfs(1, 0, 0, vis);

    cout << dp[1] << nl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t; cin >> t;
    while (t--)
        solve();
}