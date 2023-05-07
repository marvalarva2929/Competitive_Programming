using namespace std;
#include <bits/stdc++.h>
#define int long long
#define nl '\n'

const int mxn = 3010;
int a[mxn];
int n, k, t;

int closest(int x) {
	int ans = x;
	if (x == 0) {
		for (int i = 0; i < n; i++)
			ans = max(ans, a[i]/k);
	
	} else {
		for (int i = 1; i < n; i++) {
			int val = min(k, a[i]/x);
			ans = max(ans, a[i]/val);
		}
	}
	cout << x << " " << ans << nl;
	return ans;
}

void solve() {
	cin >> n >> k;
	int vu = INT_MAX;

	for (int i = 0; i < n; i++)
		cin >> a[i];

	if (n == 1) {
		cout << 0 << nl;
		return;
	}
	set<int> poss;
//	for (int i = 1; i <= k; i++)
//		if (a[0]/i <= a[0]) 
//			poss.insert(a[0]/i);
	
	for (int x = 0; x <= a[0]; x++) {
		int ans = x;	
		if (x == 0) {
			for (int i = 0; i < n; i++)
				ans = max(ans, a[i]/k);
	
		} else {
			for (int i = 0; i < n; i++) {
				int val = min(k, a[i]/x);
				ans = max(ans, a[i]/val);
			}
		}
		vu = min(vu, ans - x);
	}
	cout << vu << nl;
	return;
}

signed main() {
	cin.tie(0)->sync_with_stdio(false);

	cin >> t;
	while (t--)	
		solve();
	return 0;
}
