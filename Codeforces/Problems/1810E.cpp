#include <bits/stdc++.h>
#define int long long
#define nl " \n"
#define pi pair<int, int>
#define ff first
#define ss second

using namespace std;
const int mxn = 2e5;
vector<int> adj[mxn];
int a[mxn];

void solve() {
    int n, m; cin >> n >> m;
    fill(adj, adj + n, vector<int>());

    for (int i = 0; i < n; i++)
        cin >> a[i];
    
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v; --v, --u;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    auto cmp = [](pi& x, pi& y) -> bool {
        return a[x.ss] > a[y.ss]; 
    };
    
    vector<int> vis(n, -1);
    for (int ii = 0; ii < n; ii++) {
        if (a[ii] != 0 || vis[ii] != -1) continue;
        
        int cur = 1;
        priority_queue<pi, vector<pi>, decltype(cmp)> pq(cmp);
        vis[ii] = ii;
        for (int nex : adj[ii])
            pq.push({ii, nex}); 
        int cnt = 0;

        while (pq.size()) {
            pi fr = pq.top();
            pq.pop();
            if (vis[fr.ss] == ii) continue;
            
            vis[fr.ss] = ii;
            if (a[fr.ss] > cur) break;
            cur++;

            for (int nex : adj[fr.ss])
                if (vis[nex] < ii)
                    pq.push({fr.ss, nex});
        }
    
        if (cur == n) { cout << "YES" << nl; return; }
    }
    
    cout << "NO" << nl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t; cin >> t;
    while (t--)
        solve();
}

