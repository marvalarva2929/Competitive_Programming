#include <bits/stdc++.h>
#include <queue>
#define int long long
#define nl " \n"
#define pi pair<int, int>
#define ff first
#define ss second

using namespace std;
const int mxn = 2e5;
vector<int> adj[mxn];
int mn[mxn];

void solve() {
	int n, m; cin >> n >> m;
	fill(adj, adj + n, vector<int>());
	fill(mn, mn + n, n + 1);

	for (int i = 0; i < m; i++) {
		int u, v; cin >>u >> v;
		--u, --v;
		adj[u].push_back(v);
	}
	
	string ans = "1";
	pi mx = {0, 0};
	priority_queue<pi> pq;
	
	mn[0] = 0;
	
	for (int x : adj[0]) {
		mn[x] = min(mn[x], (int)1);				
		pq.push({x - mn[x], x});
	}
	
	for (int i = 1; i < n - 1; i++) {
		while (pq.size()) if (pq.top().ss <= i) pq.pop(); else break;
		
		if (pq.size()) {
			int t = pq.top().ss;
//			cout << i << " : " << pq.top().ff << " " << pq.top().ss << endl;
			if (mn[t] < t - i) ans.push_back('0');
			else ans.push_back('1');
		} else ans.push_back('1');
		
		mn[i] = min(mn[i], mn[i - 1] + 1);
		for (int x : adj[i]) {
			mn[x] = min(mn[x], mn[i] + 1);
			pq.push({x - mn[x], x});
		}				
	}
	
	cout << ans << endl;
}

signed main() {
	cin.tie(0)->sync_with_stdio(false);

	int t; cin >> t;
	while (t--)
		solve();
}
	
