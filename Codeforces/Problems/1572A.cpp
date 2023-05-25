#include <bits/stdc++.h>
#define int long long
#define nl '\n'

using namespace std;
    
const int mxn = 2e5;
vector<int> adj[mxn];
bool known[mxn];
bool has[mxn];
bool vis[mxn];
int times[mxn];

void dfs(int cur) {
    int ans = 0;
    if (vis[cur])
        return;
    vis[cur] = true; 
    if (known[cur]) {
        times[cur] = 1;
        return; 
    }
    for (int nex : adj[cur]) {
        dfs(nex);
        if (times[nex] == -1) {
            times[cur] = -1;
            return;
        }
        ans = max(ans, times[nex] + (nex > cur));
    }
    times[cur] = ans;
}

void solve() {
    int n; cin >> n;
    fill(times, times + n, -1);
    fill(has, has + n, 0);
    fill(known, known + n, 0);
    fill(adj, adj + n, vector<int>());
    fill(vis, vis + n, 0);

    for (int i = 0; i < n; i++) {
        int k; cin >> k;
        if (k == 0)
            known[i] = 1;
        for (int j = 0; j < k; j++) {
            int x; cin >> x;
            adj[i].push_back(--x);
            has[x] = true;
        }
    }

    for (int i = 0; i < n; i++)
        if (!has[i])
            dfs(i);

    int ans = -1;
    for (int i = 0; i < n; i++) 
        if (times[i] == -1) {
            cout << -1 << nl;
            return;
        } else ans = max(ans, times[i]);

    cout << ans << nl;

}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t; cin >> t;
    while (t--)
        solve();
}
