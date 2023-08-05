using namespace std;
#include <bits/stdc++.h>
#define int long long
#define nl '\n'
#define MAX (int)2e5 + 10
vector<int> adj[MAX];
int h[MAX];
vector<tuple<int, int, int>> orders;
int s = 0;

void fill(int past, int curr) {
    h[curr] -= s;
    for (int child : adj[curr]) {
        if (child != past) {
            fill(curr, child);
            h[curr] += h[child];
        }
    }
}

void dfs(int past, int curr) {
    for (int child : adj[curr])
        if (child != past) {
            if (h[child] >= 0) dfs(curr, child);
            if (h[child] > 0) orders.emplace_back(child, curr, h[child]);
        }
    
    for (int child : adj[curr])
        if (child != past && h[child] < 0) {
            orders.emplace_back(curr, child, -h[child]);
            dfs(curr, child);
        }
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int n; cin >> n;
    for (int i = 0; i < n; i++)
        cin >> h[i], s += h[i];

    s /= n;
    
    for (int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v;
        --u, --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    fill(0, 0);
    dfs(0, 0);

    cout << orders.size() << nl;

    for (auto a : orders) cout << get<0>(a) + 1 << " " << get<1>(a) + 1 << " " << get<2>(a) << "\n";
    return 0;
}
