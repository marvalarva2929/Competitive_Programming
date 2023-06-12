#include <bits/stdc++.h>
#define int long long
#define nl '\n'

using namespace std;

const int mxn = 2e5, LOG = 20;
vector<int> adj[mxn];
int up[mxn][LOG];
bool ina[mxn], inb[mxn];
set<int> a, b;
int n, d;
int ans = 0;

void dfsDepth(int cur, int prv) {
    up[cur][0] = prv;
    if (prv != -1)
        for (int i = 1; i < LOG; i++) {
            if (up[cur][i - 1] == -1) { up[cur][i] = -1; continue; }
            up[cur][i] = up[up[cur][i - 1]][i - 1];
        }

    for (int nex : adj[cur])
        if (nex != prv)
            dfsDepth(nex, cur);
}

bool dfs(int cur, int prv, bool tpe) {
    
    bool is = tpe ? a.count(cur) : b.count(cur);

       for (int nex : adj[cur])
        if (nex != prv)
            is |= dfs(nex, cur, tpe);
    
    if (is) {
        if (tpe) ina[cur] = 1;
        else inb[cur] = 1;
    }

    return is;
}

int anc(int n, int k) {
    for (int i = 19; i >= 0; i--)
        if (k & (1 << i)) {
            n = up[n][i];
            if (n == -1) return -1;
        }
    return n;
}
signed main() {
    cin.tie(0)->sync_with_stdio(false);

    cin >> n >> d;

    for (int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v; --u, --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    for (int i = 0; i < LOG; i++)
        up[0][i] = -1;
   
    dfsDepth(0, -1);
    
    int ia; cin >> ia;
    for (int i = 0; i < ia; i++) {
        int x; cin >> x; --x;
        a.insert(x);
        b.insert(anc(x, d)); 
    }

    int ib; cin >> ib;
    for (int i = 0; i < ib; i++) {
        int x; cin >> x; --x;
        b.insert(x);
        a.insert(anc(x, d)); 
    }
   
    dfs(0, -1, 0);
    dfs(0, -1, 1);
 
    ia = 0;
    ib = 0;
    
    for (int i = 0; i < n; i++) 
        ia += ina[i],
        ib += inb[i];

    ans += (ia - 1) * 2;
    ans += (ib - 1) * 2;

    cout << ans << nl;    
}
