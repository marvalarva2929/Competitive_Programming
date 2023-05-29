#include <bits/stdc++.h>
#define int long long
#define nl '\n'
#define pi pair<int, int>
#define ff first
#define ss second

using namespace std;

const int mxn = 2000;
set<int> adj[mxn];
vector<bool> vis;
int n, m;

vector<int> path(int i, int k) {
    queue<pi> pc;
    vector<int> previous(n, -1);
    pc.push({k, i});

    while (pc.size()) {
        int prv = pc.front().ff, cur = pc.front().ss;
        pc.pop();
        
        if (vis[cur]) continue;
        vis[cur] = true;
        previous[cur] = prv;

        for (int nex : adj[cur]) 
            if (nex != prv) {
                if (adj[k].count(nex)) { previous[k] = nex; previous[nex] = cur; return previous; }
                if (!vis[nex]) pc.push({cur, nex});
            }
    }
    return vector<int>();
}    

void solve() {
    cin >> n >> m;
    vis.resize(n);
    vector<pi> ans;
    fill(adj, adj + n, set<int>());

    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v; --u, --v;
        adj[u].insert(v);
        adj[v].insert(u);
    }
    
    for (int i = 0; i < n; i++) {
        if (adj[i].size() >= 4) {
            for (int j : adj[i]) {
                fill(vis.begin(), vis.end(), 0);
                vector<int> ret = path(j, i);
                
                if (ret.size()) {
                    set<int> allnodes;
                    int cur = i;
                   
                    do 
                        ans.push_back({ret[cur], cur}), 
                        cur = ret[cur],
                        allnodes.insert(ret[cur]),
                        allnodes.insert(cur);
                    while (cur != i);
                    
                    int cnt = 0;
                    for (int nex : adj[i]) {
                        if (cnt == 2) break;
                        else if (!allnodes.count(nex))
                            ans.push_back({i, nex}), cnt++;
                    }
                
                    cout << "YES" << nl;
                    cout << ans.size() << nl;
                    for (pi p : ans)
                        cout << p.ff + 1 << " " << p.ss + 1 << nl;
                    return;
                }
            }
        }
    }

    cout << "NO" << nl;
    return;
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t; cin >> t;
    while (t--)
        solve();
}
