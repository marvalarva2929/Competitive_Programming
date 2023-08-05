#include <bits/stdc++.h>
#define int long long
#define nl endl
#define pi pair<int, int>
#define ff first
#define ss second

using namespace std;
const int mxn = 1e5;
vector<int> adj[mxn + 1];
int vis[mxn];
int n, m;
set<int> a, b;

void dfsmx(int c = 0) {
    vis[c] = 1;
    a.insert(c);

    for (int nex : adj[c])
        if (!vis[nex])
            dfsmx(nex);
}

void dfsmn(int c = n - 1) {
    vis[c] = 1;
    b.insert(c);

    for (int nex : adj[c])
        if (!vis[nex])
            dfsmn(nex); 
}

int dfsfind(int c, pi& mn) {
    vis[c] = 1;
    
    {
        auto it = a.lower_bound(c);
        if (it != a.end()) mn.ff = min(mn.ff, abs(*it - c));
        if (it != a.begin()) mn.ff = min(mn.ff, abs(*(--it) - c));
        
        it = b.lower_bound(c);
        if (it != b.end()) mn.ss = min(mn.ss, abs(*it - c));
        if (it != b.begin()) mn.ss = min(mn.ss, abs(*(--it) - c));
    }

    for (int nex : adj[c])
        if (!vis[nex])
            dfsfind(nex, mn);

    return (mn.ff * mn.ff) + (mn.ss * mn.ss);
}

void solve() {
    cin >> n >> m;
    
    fill(adj, adj + n, vector<int>());
    fill(vis, vis + n, 0);
    a = set<int>();
    b = set<int>();

    for (int i = 0; i < m ;i++) {
        int u, v; cin >> u >> v; --u, --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    dfsmx();
    fill(vis, vis + n, 0);
    dfsmn();
    fill(vis, vis + n, 0);
    
    int mn = LLONG_MAX;

    for (int i = 0; i < n; i++)
        if (!vis[i]) {
            pi pass = {LLONG_MAX, LLONG_MAX};
            mn = min(mn, dfsfind(i, pass));
        } 
    
    cout << mn << nl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t; cin >> t;
    while (t--)
        solve();
}
