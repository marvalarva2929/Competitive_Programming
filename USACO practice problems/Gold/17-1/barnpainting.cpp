#include <bits/stdc++.h>
#define int long long
#define nl " \n"
#define pi pair<int, int>
#define ff first
#define ss second

using namespace std;
const int mxn = 1e5, MOD = 1e9 + 7;
vector<int> adj[mxn];
vector<int> g[mxn];
int w[mxn][3];

void dfs(int c, int p) {
	for (int v : adj[c])
		if (v != p) {
			dfs(v, c);
		}
	
	
	for (int x : g[c]) {
		w[c][x] = 1;

		int a = (x + 1) % 3,
			b = (x + 2) % 3;

		for (int v : adj[c])
			if (v != p) {
				w[c][x] = w[c][x] * (w[v][a] +  w[v][b] % MOD) % MOD;
			}

//		cout << c << " " << x << " : " << w[c][x] << endl;
//		cout << endl;	
	}	
}

void solve() {

	ifstream cin("barnpainting.in");
	ofstream cout("barnpainting.out");



	int n, k; cin >> n >> k;
	for (int i = 0; i < n; i++)
		g[i] = {0, 1, 2};

	for (int i = 0; i < n - 1; i++) {
		int u, v; cin >> u >> v; --u, --v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	for (int i = 0; i < k; i++) {
		int j, p; cin >> j >> p; --j, --p;
		g[j] = {p};
	}

	dfs(0, -1);
	int ans = ((w[0][0] + w[0][1]) % MOD + w[0][2]) % MOD;
	while (ans < 0) ans += MOD;
	cout << ans << endl;
}

signed main() {
	cin.tie(0)->sync_with_stdio(false);
	
	int t = 1;
	while (t--)
		solve();
}
	
