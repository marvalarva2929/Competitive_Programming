using namespace std;
#include <bits/stdc++.h>
#define int long long
#define nl '\n'

const int mxn = 2e5 + 10;
int a[mxn];

bool works(string s) {
	int cnt = 0;
	int n = s.size();
	for (int i = 0; i < n; i++) {
		if (cnt < 0) {
			return false;
		cout << cnt << nl;
	return cnt == 0;
}

void solve() {
	string t; cin >> t;
	int n = t.size();
	int l = 0, r = 0;
	for (int i = 0; i < n; i++)
		l += t[i] == ')',
		r += t[i] == '(';
	int nll = n/2 - r;
	int nr = n/2 - l;
	if (nr == 0 && nll == 0) {
		cout << "YES" << nl;
		return;
	}
	for (int i = 0; i < n && nll > 0; i++) 
		if (t[i] == '?') 
			t[i] = (nll == 1 ? ')' : '('),
			nll--;
	for (int i = n - 1; i >= 0 && nr > 0; i--)
		if (t[i] == '?')
			t[i] = (nr == 1 ? '(' : ')'),
			nr--;
	 // cout << t << nl;
	cout << (works(t) ? "NO" : "YES") << nl;
}		

signed main() {
	cin.tie(0)->sync_with_stdio(false);

	int t; cin >> t;
	while (t--)	
		solve();
}
