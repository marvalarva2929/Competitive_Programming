#include <bits/stdc++.h>
#define int long long
#define nl " \n"
#define pi pair<int, int>
#define ff first
#define ss second

using namespace std;
const int mxn = 2e3;

vector<int> adj[mxn];
bool vis[mxn][mxn];
int dp[mxn][mxn];
int a[mxn];

void solve() {
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        char c; cin >> c;
        a[i] = c - 'a';
    }
    
    fill(adj, adj + n, vector<int>());
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            vis[i][j] = dp[i][j] = 0;

    for (int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v; --u, --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    queue<pair<pi, pi>> pc;
    for (int i = 0; i < n; i++)
        for (int j : adj[i])
            pc.push({{i, i}, {j, j}});

    for (int i = 0; i < n; i++)
        dp[i][i] = vis[i][i] = 1;

    while (pc.size()) {
        auto edge = pc.front(); pc.pop(); 
         
        int f = edge.ff.ff;
        int s = edge.ss.ss;
        
        int fs = edge.ff.ss;
        int sf = edge.ss.ff;

        vis[f][s] = 1;
        
        if (a[f] == a[s]) dp[f][s] = max(dp[f][s], (f == fs ? 0 : max(dp[fs][sf], dp[sf][fs])) + 2);
        dp[f][s] = max({dp[f][s], max(dp[sf][s], dp[s][sf]), max(dp[f][sf], dp[sf][f])});
    
        for (int j : adj[s]) {
            if (!vis[f][j]) {
                auto edgen = edge;
                edgen.ss.ss = j;
                edgen.ss.ff = s;
                if (edgen.ff.ff == edgen.ff.ss) edgen.ff.ss = s;

                pc.push(edgen); 
            }
        }
    

        //cout << f << " " << s << " : " << dp[f][s] << nl;
    }
    
    int ans = INT_MIN;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            ans = max(ans, dp[i][j]);

    cout << ans << nl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t; cin >> t;
    while(t--)
        solve();
}
