#include <bits/stdc++.h>
#define int long long
#define nl " \n"
#define pi pair<int, int>
#define ff first
#define ss second

using namespace std;
const int mxn = 1e5;
vector<int> adj[mxn];

void solve() {
    int n; cin >> n;
    fill(adj, adj + n, vector<int>());

    for (int i = 0; i < n -1 ; i++) {
        int a, b; cin >> a >> b;
        --a, --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    int ans = 0;
    for (int i = 0; i < n; i++)
        ans += adj[i].size() == 1;
    
    cout << (ans + 1) / 2 << nl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t; cin >> t;
    while (t--)
        solve();
}
