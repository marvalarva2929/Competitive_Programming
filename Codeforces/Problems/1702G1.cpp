#include <bits/stdc++.h>
#define int long long
#define nl " \n"
#define pi pair<int, int>
#define ff first
#define ss second

using namespace std;

const int mxn = 2e5;
bool has[mxn];
vector<int> adj[mxn];
set<int> path;

bool dfsCheck(int cur, int par) {
    has[cur] = path.count(cur);
    for (int nex : adj[cur])
        if (nex != par)
            has[cur] |= dfsCheck(nex, cur);
    return has[cur];
}

void dfs(int cur, int par, bool top, bool& ans) {
    int cnt = top;
    top |= path.count(cur);


    int cnt2 = 0;
    int last = -1;

    for (int nex : adj[cur])
        if (nex != par && has[nex])
            cnt2++,
            last = nex;
    
    for (int nex : adj[cur])
        if (nex != par) {
            dfs(nex, cur, top | (cnt2 >= 2 ? 1 : cnt2 == 1 ? nex == last ? 0 : 1 : 0), ans);
            cnt += has[nex];
        }

    if (cnt > 2) ans = false;
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int n; cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v;
        --u, --v; 
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    int q; cin >> q;
    while (q--) {
        int k; cin >> k;
        path.clear();

        for (int i = 0; i < k; i++) {
            int x; cin >> x;
            path.insert(x - 1);
        }
        
        bool ans = 1;
        dfsCheck(0, -1);

        dfs(0, -1, 0, ans); 
        
        if (ans) cout << "YES" << nl;
        else cout << "NO" << nl;
    }
}
