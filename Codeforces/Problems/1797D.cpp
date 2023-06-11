#include <bits/stdc++.h>
#define int long long
#define nl '\n'
#define pi pair<int, int>
#define ff first
#define ss second

using namespace std;

const int mxn = 1e5 + 1;
int sum[mxn], a[mxn], f[mxn], sz[mxn], hs[mxn];
vector<int> adj[mxn];
set<pi> children[mxn];

void dfs(int cur, int prv) {
    sz[cur] = 1;
    f[cur] = prv;
    sum[cur] = a[cur];

    for (int nex : adj[cur])
        if (nex != prv) {
            dfs(nex, cur);
            sz[cur] += sz[nex];
            sum[cur] += sum[nex]; 
            children[cur].insert({-sz[nex], nex});
            if (sz[hs[cur]] < sz[nex] || (sz[hs[cur]] == sz[nex] && nex < hs[cur]))
                hs[cur] = nex;
        }
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
   
    dfs(1, 0);

    while (m--) {
        int op, x; cin >> op >> x;
        

        if (op == 1) cout << sum[x] << nl;
        else {
            if (!hs[x]) continue;
            int v = hs[x], p = f[x];
            
            sum[x] -= sum[v];
            sum[v] += sum[x];
           
            f[x] = v;
            f[v] = p;
           
            children[x].erase({-sz[v], v});
            children[p].erase({-sz[x], x}); 
            sz[x] -= sz[v];
            sz[v] += sz[x];
            children[v].insert({-sz[x], x});
            children[p].insert({-sz[v], v});
            
            hs[x] = children[x].size() ? (*children[x].begin()).ss : 0;
            hs[v] = children[v].size() ? (*children[v].begin()).ss : 0;
            hs[p] = children[p].size() ? (*children[p].begin()).ss : 0;
        }
    }
}
