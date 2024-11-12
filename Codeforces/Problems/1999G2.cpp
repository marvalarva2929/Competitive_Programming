#include <bits/stdc++.h>
#define int long long
#define nl " \n"
#define pi pair<int, int>
#define ff first
#define ss second

using namespace std;

int query(int a, int b) {
	cout << "? " << a << " " << b << endl;
	cout.flush();
	int ret; cin >> ret;
	return ret;
}

void ans(int x) {
	cout << "! " << x << endl;
	cout.flush();
}

void solve() {
	int l = 2, r = 1000;
	while (r - l >= 3) {
		int d = r - l;
		d = (d + 1) / 3;
		
		int a = l + d - 1;
		int b = a + d;

		int ret = query(a, b);
		if (ret == a * b) { // 3rd
			l = b + 1;
		} else if (ret == a * (b + 1)) { // 2nd
			r = b + 1;
			l = a + 1;
		} else if (ret == (a + 1) * (b + 1)) { // 1st
			r = a + 1;
		}
	}
	
	int ret = query(l, l + 1);
	if (ret == (l + 1) * (l + 2)) ans(l);
	else ans(l + 1);
}

signed main() {
	int t; cin >> t;
	while (t--)
		solve();
}
	
