#include <bits/stdc++.h>
#define int long long
#define nl " \n"
#define inf LONG_LONG_MAX
#define all(x) x.begin(), x.end()
#define pi pair<int, int>
#define ff first
#define ss second

using namespace std;

const int mxn = 2e5;
pi a[mxn];
int mx[mxn];
vector<int> adj[mxn];
int vis[mxn];
set<int> wout;
int n, m, k;

int dfs(int x) {
    if (vis[x]) return 2e18;
    if (mx[x]) return mx[x];
    vis[x] = 1;

    for (int nex : adj[x])
        if (!wout.count(nex))
            mx[x] = max(mx[x], dfs(nex) + 1);

    vis[x] = 0;
    return mx[x];
}

bool check() {
    int ret = dfs(0);
    
//    for (int x : wout)
//        cout << x << " ";
//    cout << nl;
//
//    for (int i = 1; i <= n; i++)
//        cout << mx[i] << nl[i == n];
//    
//    cout << nl;

    return ret >= k;
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);
    
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        a[i] = {x, i};
    }
    
    sort(a + 1, a + n + 1);
    
    for (int i = 0; i < m; i++) { 
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
    }
    
    for (int i = 1; i <= n; i++)
        adj[0].push_back(i);

    if (!check()) {
        cout << -1 << nl;
        return 0; 
    }

    int l = 1, r = n + 1;
    while (r - l > 1) {
        int m = (l + r) >> 1;
        wout.clear();
        for (int i = n; i >= m; i--)
            wout.insert(a[i].ss);
        fill(vis, vis + n + 1, 0);
        fill(mx, mx + n + 1, 0);
       
        int ans = check();
         
        if (ans) r = m;
        else l = m;
    }
    
    cout << a[l].ff << nl;
}
