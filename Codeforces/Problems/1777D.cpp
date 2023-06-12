#include <bits/stdc++.h>
#define int long long
#define nl '\n'


using namespace std;
const int mxn = 2e5;
const int MOD ((int)1e9 + 7);
vector<int> adj[mxn];
int ans = 0;

int power(int a, int b) {
    int ans = 1;
    while (b) {
        if (b & 1)
            ans = ans * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    
    return ans;
}

int dfs(int cur, int prv) {
    int lvl = 1;
    for (int nex : adj[cur])
        if (nex != prv)
            lvl = max(lvl, dfs(nex, cur));
    ans = ans + lvl % MOD;
    return lvl + 1;
}

void solve() {
    int n; cin >> n;
    ans = 0;
    fill(adj, adj + n, vector<int>());

    for (int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v; --u, --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    dfs(0, -1);

    cout << ans % MOD * power(2, n - 1) % MOD << nl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t; cin >> t;
    while (t--)
        solve();
}
