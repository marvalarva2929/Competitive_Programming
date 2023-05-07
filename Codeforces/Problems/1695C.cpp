using namespace std;
#include <bits/stdc++.h>
#define int long long
#define nl '\n'
	
const int mxn = 1e3 + 3;
int a[mxn][mxn];
int dp[mxn][mxn];
int n, m;

int calcMin() {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			dp[i][j] = INT_MAX;
	dp[0][0] = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			if (i > 0)
				dp[i][j] = dp[i - 1][j];
			if (j > 0)
				dp[i][j] = min(dp[i][j], dp[i][j - 1]);
			dp[i][j] += a[i][j];
		}
	return dp[n - 1][m - 1];

}

int calcMax() {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			dp[i][j] = INT_MIN;
	dp[0][0] = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (i > 0)
				dp[i][j] = max(dp[i][j], dp[i - 1][j]);
			if (j > 0)
				dp[i][j] = max(dp[i][j], dp[i][j - 1]);
			dp[i][j] += a[i][j];
		}
	}


	return dp[n - 1][m - 1];
}

void solve() {
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> a[i][j];
	if ((n + m) % 2 == 0) {
		cout << "NO" << nl;
		return;
	}
	int mn = calcMin();
	int mx = calcMax();
	cout << (mn <= 0 && mx >= 0 ? "YES" : "NO") << nl;
}

signed main() {
	cin.tie(0)->sync_with_stdio(false);

	int t; cin >> t;
	while (t--)
		solve();
}
