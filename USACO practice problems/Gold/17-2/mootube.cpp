#include <bits/stdc++.h>
#define int long long
#define nl " \n"
#define pi pair<int, int>
#define ff first
#define ss second

using namespace std;
const int mxn = 2e5;
int sz[mxn];
int id[mxn];
int ans[mxn];

int root(int idx) {
	while (idx != id[idx]) {
		idx = id[idx];
	}
	return idx;
}

void ct(int a, int b) {
	a = root(a);
	b = root(b);
	if (a == b) return;

	if (sz[a] < sz[b]) swap(a, b);
	id[b] = a;
	sz[a] += sz[b];
}

void solve() {
	ifstream cin("mootube.in");
	ofstream cout("mootube.out");

	int n, q; cin >> n >> q;
	for (int i = 0; i < n; i++)
		id[i] = i, sz[i] = 1;

	vector<pair<int, pi>> e(n - 1);
	vector<pair<pi, int>> req(q);

	for (int i = 0; i < n - 1; i++)
		cin >> e[i].ss.ff >> e[i].ss.ss >> e[i].ff,
		e[i].ss.ff--, e[i].ss.ss--;
	for (int i = 0; i < q; i++)
		cin >> req[i].ff.ff >> req[i].ff.ss, req[i].ss = i;
	
	sort(e.begin(), e.end());
	sort(req.begin(), req.end());
//	cout << endl;
	for (int i = q - 1; i >= 0; i--) {
		auto r = req[i];
		//cout << i << " : " << r.ff.ff << " " << r.ff.ss << endl;
		while (e.size() && e.back().ff >= r.ff.ff)
			ct(e.back().ss.ff, e.back().ss.ss),
//			cout << e.back().ss.ff << " " << e.back().ss.ss << endl,
			e.pop_back();
		ans[r.ss] = sz[root(r.ff.ss - 1)];	
//		cout << endl;
	}

	for (int i = 0; i < q; i++)
		cout << ans[i] - 1 << endl;
}

signed main() {
	cin.tie(0)->sync_with_stdio(false);
	
	int t = 1;
	while (t--)
		solve();
}
	
