#include <bits/stdc++.h>
#define int long long
#define nl '\n'

using namespace std;

const int mxn = 2e5;
vector<int> adj[mxn];
set<int> nxt;
int n, k;

int dfs(int cur, int maxd, int& ans) {
    int depth = 0;

    for (int nex : adj[cur])
        depth = max(dfs(nex, maxd, ans), depth);
    
    //cout << cur << " " << depth << nl;

    if (depth == maxd - 1 && !nxt.count(cur)) { 
        ans++;
     //   cout << "CUT" << nl;
        return 0;
    }

    return depth + 1;
}

bool check(int x) {
    int req = 0;
    //cout << x << " : " << nl; 
    dfs(0, x, req);
    return req <= k;
}

void solve() {
    cin >> n >> k;
    nxt.clear();
    fill(adj, adj + n, vector<int>());
    
    for (int i = 0; i < n - 1; i++) {
        int x; cin >> x;
        if (x == 1) nxt.insert(i + 1);

        adj[x - 1].push_back(i + 1);
    }
    
    nxt.insert(0);

    int l = 1, r = n;
    int ans = INT_MAX;

    while (l < r) {
        int m = (l + r) >> 1;
        if (check(m))
            r = m,
            ans = min(ans, r);
        else l = m + 1;
    }

    cout << ans << nl; 
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t; cin >> t;
    while (t--)
        solve();
}
