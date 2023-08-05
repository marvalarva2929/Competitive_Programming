#include <bits/stdc++.h>
#define int long long
#define nl " \n"
#define pi pair<int, int>
#define ff first
#define ss second

using namespace std;
const int mxn = 2e5;
vector<int> adj[mxn];
vector<int> top;
bool vis[mxn];
int in[mxn], ans[mxn];

void dfs(int x) {
    vis[x] = 1;
    for (int y : adj[x])
        if (!vis[y])
            dfs(y);
    top.push_back(x);
}

void solve() {
    int n, m; cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v; --u, --v;
        in[v]++;
        adj[u].push_back(v);
    }
    
    top = vector<int>();    
    for (int i = 0; i < n; i++)
        if (!vis[i])
            dfs(i);
    
    for (int j = top.size() - 1; j >= 0; j--) {
        int i = top[j];

        if (in[i] == 1) ans[i] = 0;
        if (adj[i].size() > 1)
            for (int j : adj[i])
                ans[j] = max(ans[j], ans[i] + 1);
    }

    cout << *max_element(ans, ans + n) + 1 << nl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t = 1;
    while(t--)
        solve();
}
