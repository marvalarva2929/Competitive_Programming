using namespace std;
#include <bits/stdc++.h>
#define int long long
#define nl '\n'

const int mxn = 2e5 + 10;

void solve() {
	int n; cin >> n;
	string aa, bb;
	cin >> aa >> bb;

	if (aa[0] != bb[0] || aa[aa.size() - 1] != bb[bb.size() -1]) {
		cout << -1 << nl;
		return;
	}	

	bitset<mxn> a(aa), b(bb);

	bitset<mxn> upa, upb;

	for (int i = 0; i < n - 1; i++)
		upa[i] = a[i] ^ a[i + 1];
	for (int i = 0; i < n - 1; i++)
		upb[i] = b[i] ^ b[i + 1];

	if (upb.count() != upa.count()) {
		cout << -1 << nl;
		return;
	}

	int i = 0, j = 0;
	int ans = 0;
	while (i < n && j < n) {
		while (i < n && !upa[i])
			i++;
		while (i < n && !upb[j])
			j++;
		if (i < n && j < n)
			ans += abs(i - j);
		i++;
		j++;
	}
	cout << ans << nl;
}

signed main() {
	cin.tie(0)->sync_with_stdio(false);
	int t; cin >> t;
	while (t--)
		solve();
}
