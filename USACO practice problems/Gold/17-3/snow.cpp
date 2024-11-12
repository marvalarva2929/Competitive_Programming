#include <bits/stdc++.h>
#define int long long
#define nl " \n"
#define pi pair<int, int>
#define ff first
#define ss second

using namespace std;
const int mxn = 1e5;
int n, m; 
pi a[mxn];
pi b[mxn];
int ans[mxn];
int id[mxn];
int sz[mxn];

int root(int idx) {
	while (idx != id[idx]) {
		idx = id[idx];
		id[idx] = id[id[idx]];
	}
	return idx;
}

void ct(int a, int b) {
	a = root(a);
	b = root(b);
	
	if (a == -1 || b == n) return;
	if (min(sz[a], sz[b]) == 0) return;
	if (sz[a] < sz[b]) swap(a, b);

	id[b] = a;
	sz[a] += sz[b];
}

void solve() {
	ifstream cin("snowboots.in");
	ofstream cout("snowboots.out");

	cin >> n >> m;
	iota(id, id + n, 0);
	fill(sz, sz + n, 0);

	for (int i = 0; i < n; i++)
		cin >> a[i].ff, a[i].ss = i;
	for (int i = 0; i < m; i++)
		cin >> b[i].ff >> b[i].ss;
	vector<int> c(m);
	vector<int> ic[m];

	iota(c.begin(), c.end(), 0);
	sort(c.begin(), c.end(), [](const int & a, const int & j) -> bool {
				return b[a].ff > b[j].ff;
			});
	sort(a, a + n);

	int idx = n - 1;
	for (int i = 0; i < m && idx >= 0; i++)  
		while (idx >= 0 && a[idx].ff > b[c[i]].ff) ic[i].push_back(a[idx--].ss); 	
	
	sort(a, a + n, [](const pi & i, const pi & j) -> bool {
			return i.ss < j.ss; 
			});
	
	int mx = 0;
	for (int i = 0; i < m; i++) {
		for (int x : ic[i]) {
			sz[x] = 1;
			ct(x - 1, x);
			ct(x, x + 1);
			mx = max(mx, sz[root(x)]);
		}	
		if (mx >= b[c[i]].ss) ans[c[i]] = 0;
		else ans[c[i]] = 1;
	}

	for (int i = 0; i < m; i++)
		cout << ans[i] << endl;
}

signed main() {
	cin.tie(0)->sync_with_stdio(false);
	
	int t= 1;
	while (t--)
		solve();
}
	
