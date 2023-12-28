#include <bits/stdc++.h>
#define int long long
#define nl " \n"
#define pi pair<int, int>
#define ff first
#define ss second

using namespace std;
const int mxn = 1e5;
set<int> adj[mxn];

void solve() {
    int n; cin >> n;
    fill(adj, adj + n, set<int>());

    int acl = 0;

    for (int i = 0; i < n - 1; i++) {
        int a, b; cin >> a >> b; --a, --b;
        adj[a].insert(b);
        adj[b].insert(a);
    }
        
    if (n == 2) {
        cout << "NO" << nl;
        return;
    }
    
    set<int> bl;
    for (int i = 0; i < n; i++)
        if (adj[i].size() == 1)
            bl.insert(i);
    
    for (int i = 0; i < n; i++) {
        if (bl.count(i)) continue;
        int s = 0;
        for (int x : adj[i])
            s += !bl.count(x);
        
        if (s == 1) acl++;
    }
    
    cout << (acl > 2 ? "NO" : "YES") << nl; 
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t; cin >> t;
    while (t--)
        solve();
}
