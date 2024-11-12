#include <bits/stdc++.h>
#define int long long
#define nl " \n"
#define pi pair<int, int>
#define ff first
#define ss second

using namespace std;
const int mxn = 3e5+1;
int a[mxn];

void solve() {
	int n, k; cin >> n >> k;

	vector<vector<int>> ans(n + 1, vector<int>(k + 1, 0));

	int s = 0;
	for (int i = 1; i <= n; i++)
		cin >> a[i], s += a[i];
	
	for (int i = 2; i <= n; i++) {
		int mn = a[i], su = a[i];
		for (int j = 1; j <= min(i - 1, k); j++) {
			mn = min(mn, a[i - j]); su += a[i - j];
			int d = su - (mn * (j + 1));
		

			for (int m = 0; m + j <= min(k, i - 1); m++) {
				ans[i][m + j] = max(ans[i][m + j], ans[i - j - 1][m] + d);
			}		
		}

		for (int j = 0; j <= k; j++)
			ans[i][j] = max(ans[i][j], ans[i - 1][j]);
	}
		
	for (int j = 1; j <= k; j++)
		ans[n][j] = max(ans[n][j], ans[n][j - 1]);

	cout << s - ans[n][k] << nl;
}

signed main() {
	cin.tie(0)->sync_with_stdio(false);

	int t; cin >> t;
	while (t--)
		solve();
}
	
