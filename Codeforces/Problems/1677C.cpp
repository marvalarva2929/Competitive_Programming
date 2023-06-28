#include <bits/stdc++.h>
#define int long long
#define nl " \n"
#define pi pair<int, int>
#define ss second
#define ff first
#define all(x) x.begin(), s.end()

using namespace std;

const int mxn = 1e5;
int a[mxn], b[mxn];
bool vis[mxn+1];
vector<int> adj[mxn+1];
int cnt = 0;

void dfs(int i) {
    vis[i] = 1;
    for (int j : adj[i])
        if (!vis[j])
            dfs(j);
    cnt++;
}

void solve() {
    int n; cin >> n;
    fill(vis + 1, vis + n + 1, 0);
    fill(adj + 1, adj + n + 1, vector<int>());

    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];

    for (int i = 0; i < n; i++)
        if (a[i] != b[i])
            adj[a[i]].push_back(b[i]),
            adj[b[i]].push_back(a[i]);
    
    int ans = 0;
    int c = 0;

    for (int i = 1; i <= n; i++)
        if (!vis[i] && adj[i].size()) {
            dfs(i); 
            c += cnt/2;
            cnt = 0;
        }
    
    cout << 2 * c * (n - c) << nl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t; cin >> t;
    while (t--)
        solve();
}
