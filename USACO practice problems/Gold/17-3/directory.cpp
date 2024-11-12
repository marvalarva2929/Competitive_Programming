#include <bits/stdc++.h>
#define int long long
#define nl " \n"
#define pi pair<int, int>
#define ff first
#define ss second

using namespace std;
const int mxn = 1e5;
vector<int> adj[mxn];
int sz[mxn];
int dist[mxn];
int len[mxn];
int ans = LLONG_MAX;
int ad;

int dfs1(int x) {
	for (int e : adj[x])
		dfs1(e);	
	
	for (int e : adj[x])
		dist[x] += dist[e] + (len[e] * sz[e]),
		sz[x] += sz[e];

	if (adj[x].size() == 0 && x > 0) sz[x] = 1, dist[x] = 0, ad++;
	return sz[x];
}

void dfs2(int x, int r) {
//	cout << x << " : " << sz[x] << " " << r << " " << dist[x] << " " << len[x] << endl;
//	cout << x << " : " << sz[x] << " " << r << " " << dist[x] << endl;
	ans = min(ans, r);
	

	for (int e : adj[x])
		dfs2(e, r - (sz[e] * len[e]) + ((ad - sz[e]) * 3)) ;
}

void solve() {
	ifstream cin("dirtraverse.in");
	ofstream cout("dirtraverse.out");

	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		len[i] = s.length();
		int m; cin >> m;
		for (int j = 0; j < m; j++) {
			int x; cin >> x;
			adj[i].push_back(--x);
		}
		len[i] += (m > 0);
	}

	dfs1(0);
	dfs2(0, dist[0]);

	cout << ans << endl;
}

signed main() {
	cin.tie(0)->sync_with_stdio(false);
	
	int t = 1;
	while (t--)
		solve();
}
	
