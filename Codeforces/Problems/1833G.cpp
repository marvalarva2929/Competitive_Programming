#include <bits/stdc++.h>
#define int long long
#define nl '\n'
#define pi pair<int, int>
#define ff first
#define ss second

using namespace std;

const int mxn = 2e5;
vector<int> adj[mxn];
vector<pi> cuts;
map<pi, int> edges;

bool imp = false;

int dfs(int cur, int par) {
    int ans = 0;
    if (imp) return 0;
    
    vector<int> children;

    for (int nex : adj[cur])
        if (nex != par) {
            int res = dfs(nex, cur);
            if (res)
                children.push_back(res);
        }
        
    //cout << cur + 1 << " : ";
    //for (int child : children)
    //    cout << child << " ";
    //cout << nl;

    if (children.size() > 2) {
        imp = true;
        return 0;
    }

    if (children.size() == 0)
        return 1;

    if (children.size() == 1) {
        if (children[0] == 2) {
            if (par != -1)
                cuts.push_back({par, cur});
            return 0;
        } else if (children[0] == 1) { 
            return 2;
        }
    }

    if (children.size() == 2 && children[0] == children[1] && children[0] == 1) {
        if (par != -1)
            cuts.push_back({par, cur});
        return 0;
    }

   imp = true;
   return 0;
}

void solve() {
    int n; cin >> n;
    fill(adj, adj + n, vector<int>());
    imp = false;
    cuts.clear();
    edges.clear();

    for (int i = 0; i < n - 1; i ++) {
        int u, v; cin >> u >> v; --u, --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        edges[{u, v}] = i + 1;
        edges[{v, u}] = i + 1;
    }

    if (n % 3) {
        cout << -1 << nl;
        return;
    }

    dfs(0, -1);
    
    if (imp) {
        cout << -1 << nl;
        return;
    }

    cout << cuts.size() << nl;
    for (pi cut : cuts)
        cout << edges[cut] << " ";
    cout << nl;


}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t; cin >> t;
    while (t--)
        solve();
}
