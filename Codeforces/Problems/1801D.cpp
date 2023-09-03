#include <bits/stdc++.h>
#define int long long
#define nl " \n"
#define pi pair<int, int>
#define ff first
#define ss second

using namespace std;
const int mxn = 8e2, mxm = 3e3;
int w[mxn], j[mxn];
vector<pi> adj[mxm];
pi tn[mxn];
int n, m, p;

void smx(pi& a, pi b) {
    if (a.ff == b.ff) {
        if (a.ss < b.ss)
            a = b;
    } else if (a.ff > b.ff) a = b; 
}

void gettn(int x) {
    if (tn[x].ss == -1) return;
    
    priority_queue<pi, vector<pi>, greater<pi>> pc;
    vector<bool> vis(n, 0);
 
    for (pi edge : adj[x])
        pc.push(edge);
    
    while (pc.size()) {
        pi tp = pc.top();
        pc.pop();
        vis[tp.ss] = 1;
        //cout << x << " : " << tp.ss << nl;
        if ((tp.ss == n - 1 || w[tp.ss] > w[x])) {
            int have = tn[x].ss;
            int need = tp.ff;
            have -= min(tn[x].ss, need);
            need -= min(tn[x].ss, need);
            int rq = (need + w[x] - 1) / w[x];
            
            have += (rq * w[x]) - need;

            //cout << have << " " << need << " " << rq << nl;
            smx(tn[tp.ss], {rq + tn[x].ff, have});
            //cout << tn[tp.ss].ff << nl << nl;
            continue;
        }

        for (pi edge : adj[tp.ss])
            if (!vis[edge.ss])
                pc.push({edge.ff + tp.ff, edge.ss});
    }

}
 
void solve() {
    cin >> n >> m >> p;
    iota(j, j + n, 0);
    fill(adj, adj + n, vector<pi>());
    fill(tn, tn + n, make_pair(LLONG_MAX, -1));
    
    tn[0] = {0, p};
    
    for (int i = 0; i < n; i++)
        cin >> w[i];
    
    w[n - 1] = LLONG_MAX;

    for (int i = 0; i < m; i++) {
        int u, v, s; cin >> u >> v >> s; --v, --u;
        adj[u].emplace_back(s, v);
    }
    
    sort(j, j + n, [](const int & a, const int & b) -> bool {
            return w[a] < w[b];
        }); 

    int jj = 0;
    while (j[jj] != 0) jj++;
    
    for (int i = jj; i < n - 1; i++)
        gettn(j[i]);
    
    if (tn[n - 1].ss == -1) cout << -1 << nl;
    else cout << tn[n - 1].ff << nl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t; cin >> t;
    while (t--)
        solve();
}
