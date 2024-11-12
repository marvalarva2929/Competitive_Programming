#include <bits/stdc++.h>
#define int long long
#define nl " \n"
#define pi pair<int, int>
#define ff first
#define ss second

using namespace std;
const int mxn = 1e5;
int a[mxn], b[mxn];
int t[mxn * 2];
int n;

void build() {
	for (int i = n; i < (n + n); i++)
		t[i] = b[i - n];
	for (int i = n - 1; i >= 0; i--)
		t[i] = max(t[i<<1], t[i<<1|1]);
}

int gmx(int l, int r) {
	int ret = b[l];
	for (l += n, r += n; l < r; l>>=1, r>>=1) {
		if (l&1) ret = max(ret, t[l++]);
		if (r&1) ret = max(ret, t[--r]);
	}

	return ret;
}

void solve() {
	ifstream cin("hayfeast.in");
	ofstream cout("hayfeast.out");

	int  m; cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> a[i] >> b[i];
	build();

	int l = 0, r = 0;
	int s = 0;
	int ans = INT_MAX;

	while (true) {
		while (s < m && r < n) s += a[r++];	
		//cout << l << " " << r << " " << s << endl;
		if (s >= m) ans = min(ans, gmx(l, r));
		s -= a[l++];
		if (r == n) break;
	}

	cout << ans << endl;
}

signed main() {
	cin.tie(0)->sync_with_stdio(false);
	
	int t= 1;
	while (t--)
		solve();
}
	
