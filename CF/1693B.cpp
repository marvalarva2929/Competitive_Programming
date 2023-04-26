using namespace std;
#include <bits/stdc++.h>
#define int long long
#define nl '\n'
#define pi pair<int, int>

const int mxn = 2e5 + 10;
vector<int> adj[mxn];
pi lr[mxn];
int n; 
int ans;

int dfs(int x, int p) {
	int come = 0;
	for (int y : adj[x])
		come += dfs(y, x);
	if (come < lr[x].first) {
		ans++;
		come = lr[x].second;
	}
	come = min(come, lr[x].second);
	return come;
}

void solve() {
	ans = 0;
	cin >> n;
	for (int i = 1; i <= n; i++)
		adj[i].clear();

	for (int i = 2; i <= n; i++) {
		int x; cin >> x;
		adj[x].push_back(i);
	}

	for (int i = 1; i <= n; i++)
		cin >> lr[i].first >> lr[i].second;
	
	dfs(1, 0);

	cout << ans << nl;
}

signed main() {
	cin.tie(0)->sync_with_stdio(false);

	int t; cin >> t;
	while (t--)
		solve();
}
