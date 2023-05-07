using namespace std;
#include <bits/stdc++.h>
#define int long long
#define nl '\n'

const int mxn = 2e5 + 10;

int getPref(int x) {
	while (!(x & 1)) 
		x >>= 1;
	return x;
}

void solve() {
	int n; cin >> n;
	multiset<int> a, b;
	unordered_map<int, int> cnt;
	int mxA = 0;
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		a.insert(getPref(x));
	}
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		b.insert(x);
	}
	while(b.size()) {
		int x = *b.rbegin();
		if (!a.count(x)) {
			if (x == 1) break;
			b.erase(b.find(x));
			b.insert(x/2);
		} else {
			a.erase(a.find(x));
			b.erase(b.find(x));
		}
	}

	cout << (b.size() ? "NO" : "YES") << nl;
}

signed main() {
	
	cin.tie(0)->sync_with_stdio(false);
	int t; cin >> t;
	while (t--) 
		solve();
}
