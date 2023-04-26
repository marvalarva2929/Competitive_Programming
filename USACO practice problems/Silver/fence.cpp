using namespace std;
#include <bits/stdc++.h>
// #define int long long
#define ll long long
#define nl '\n'
#define pi pair<int, int>

const int mxn = (int)1e5;

vector<ll> adj[mxn];
vector<ll> comps[mxn];
ll comp[mxn];

void dfs(int cur, int c) {
	if (comp[cur] != -1) {
		return;
	}
	comp[cur] = c;
	for (int u : adj[cur]) {
		dfs(u, c);
	}
}


ll cost(int a, int b) {
    ll dist = mxn;
	for (int u : comps[a]) {
		int i = lower_bound(
			comps[b].begin(), comps[b].end(), u
		) - comps[b].begin();
		if (i > 0) {
			dist = min(dist, abs(comps[b][i - 1] - u));
		}
		if (i < comps[b].size()) {
			dist = min(dist, abs(comps[b][i] - u));
		}
	}
	/* 
	 * Returns the minimum cost of building a path 
	 * between the two components (aka dist^2)
	 */
	return (ll)dist * dist;
}

void solve() {
    int n, m; 
    cin >> n >> m;


	for (int i = 0; i < n; i++) {
		comp[i] = -1;
		adj[i].clear();
		comps[i].clear();
	}
    // fill(comp, comp + n + 1, 0);
    // fill(adj, adj + n + 1, vector<int>());
    // fill(comps, comps + n + 1, vector<int>());

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		adj[--a].push_back(--b);
		adj[b].push_back(a);
	}

    int cur = -1;
	for (int i = 0; i < n; i++) {
		if (comp[i] == -1) {
			dfs(i, ++cur);
		}
	}

	for (int i = 0; i < n; i++) {
		comps[comp[i]].push_back(i);
	}
    
    // int s = comp[0];
    // int t = comp[n - 1];

    ll ans = cost(comp[0], comp[n - 1]);
    for (int c = 1; c < cur; c++) 
        ans = min(ans, cost(c, comp[0]) + cost(c, comp[n - 1]));

    cout << ans << endl;

    // ll res = cost(comp[0], comp[n - 1]);
	// for (int c = 1; c < cur; c++) {
	// 	// Minimize the cost of building two paths
	// 	res = min(res, cost(c, comp[0]) + cost(c, comp[n - 1]));
	// }
	// cout << res << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);
    int t; cin >> t;
    for (int i = 0; i < t; i++)
        solve();
}