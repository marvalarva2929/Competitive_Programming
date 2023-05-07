using namespace std;
#include <bits/stdc++.h>
#define int long long
#define nl '\n'

const int mxn = 2e5 + 10;
int a[mxn];

void solve() {
	int n; cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	int ans = 0;
	int curh = a[0];
	for (int i = 0; i < n - 1; i++) {
		ans += abs(a[i] - a[i + 1]);
		if (a[i] > a[i + 1])
			curh -= abs(a[i + 1] -  a[i]);
	}
	ans += abs(curh);
	cout << ans << nl;

}

signed main() {
	cin.tie(0)->sync_with_stdio(false);

	int t; cin >> t;
	while (t--)
		solve();
}

