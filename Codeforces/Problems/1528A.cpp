using namespace std;
#include <bits/stdc++.h>
#define int long long
#define nl '\n'
#define MAX (int)2e5 + 10
int l[MAX], r[MAX];
vector<int> adj[MAX];
int dp[MAX][2]; // node, 0 for l , 1 for r

void dfs(int curr, int par) {
    for (int child : adj[curr])
        if (child != par)
            dfs(child, curr);
            
    for (int child : adj[curr]) 
        if (child != par)
            dp[curr][0] += max(abs(l[child] - l[curr]) + dp[child][0], abs(r[child] - l[curr]) + dp[child][1]),
            dp[curr][1] += max(abs(l[child] - r[curr]) + dp[child][0], abs(r[child] - r[curr]) + dp[child][1]);
}

void solve() {
    int n; cin >> n;
    for (int i = 0; i <= n; i++)
        dp[i][1] = dp[i][0] = 0,
        adj[i].clear();

    for (int i = 1; i <= n; i++)
        cin >> l[i] >> r[i];
    int root = 0;
    for (int i = 0; i < n - 1; i++) {
        int x, y; cin >> x >> y;
        root = x;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    dfs(root, root);

    cout << max(dp[root][1], dp[root][0]) << nl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t; cin >> t;
    while (t--)
        solve();
}