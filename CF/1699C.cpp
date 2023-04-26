using namespace std;
#include <bits/stdc++.h>
#define int long long
#define nl '\n'
#define pi pair<int, int>
#define f first
#define s second
#define mod ((int)1e9 + 7)

const int mxn = 1e5 + 10;
int a[mxn];
int pos[mxn];
pi borders[mxn];

void solve() {
	int n; cin >> n;
	vector<pi> hotspots;
	vector<int> swap;

	for (int i = 0; i < n; i++)
		cin >> a[i],
		pos[a[i]] = i;
	
	int mn = INT_MAX, mx = INT_MIN;

	for (int i = 0; i < n; i++) {
		if (pos[i] < mx && pos[i] > mn)
			borders[i] = {mn, mx},
			hotspots.push_back({pos[i], i});
		mn = min(mn, pos[i]);
		mx = max(mx, pos[i]);
	}
	sort(hotspots.begin(), hotspots.end());
	
	int ans = 1;
	for (auto hotspot : hotspots) {
		swap.push_back(abs(lower_bound(hotspots.begin(), hotspots.end(), make_pair(borders[hotspot.s].f, (int)0)) -
			upper_bound(hotspots.begin(), hotspots.end(), make_pair(borders[hotspot.s].s, (int)0))));
	}
	sort(swap.begin(), swap.end());

	for (int i = 0; i < swap.size(); i++)
		ans = (ans * (swap[i] - i) % mod) % mod;

	cout << ans % mod << nl; 
}

signed main() {
	cin.tie(0)->sync_with_stdio(false);

	int t; cin >> t;
	while (t--)
		solve();
}
