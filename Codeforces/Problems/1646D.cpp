#include <bits/stdc++.h>
#define int long long
#define nl " \n"
#define pi pair<int, int>
#define ff first
#define ss second

using namespace std;
const int mxn = 2e5;
vector<int> adj[mxn];
int w[mxn];
pair<pi, pi> store[mxn];

pair<pi, pi> dfs(int c, int p) {
    pair<pi, pi> ret = {{0, -1}, {1, -adj[c].size()}};
        
    for (int nex : adj[c])
        if (nex != p) {
            auto get = dfs(nex, c);
            ret.ff.ff += max(get.ff, get.ss).ff;
            ret.ff.ss += max(get.ff, get.ss).ss;
            
            ret.ss.ff += get.ff.ff;
            ret.ss.ss += get.ff.ss;
        }
        
    //cout << c << " : " << ret.ff.ff << " , " << ret.ff.ss << " " << ret.ss.ff << " , " << ret.ss.ss << nl;

    store[c] = ret; 
        
    return ret;
}

void dfs2(int c, int p, bool bef) {
    w[c] = 1;
    
    bool check = bef || (store[c].ff > store[c].ss);
    
    if (!check) 
        w[c] = adj[c].size();

    for (int nex : adj[c])
        if (nex != p)
            dfs2(nex, c, !check);
    
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int n; cin >> n;
   

    for (int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v; --u, --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    if (n == 2) {
        cout << 2 << " " << 2 << nl;
        cout << 1 << " " << 1 << nl;
        return 0;
    } 
   
    auto ans = dfs(0, -1);
    dfs2(0, -1, 0);

    cout << max(ans.ff, ans.ss).ff << " " << -max(ans.ff, ans.ss).ss << nl;
    
    for (int i = 0; i < n; i++)
        cout << w[i] << nl[i == n- 1];
}
