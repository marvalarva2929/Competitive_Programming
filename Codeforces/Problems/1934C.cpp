#include <bits/stdc++.h>
#define int long long
#define nl " \n"
#define pi pair<int, int>
#define ff first
#define ss second

using namespace std;

int query(int x, int y) {
	cout << "? " << x + 1 << " " << y + 1 << endl;
	cout.flush();
	int ret; cin >> ret;
	return ret;
}

void ans(int x, int y) {
	cout << "! " << x + 1 << " " << y + 1 << endl;
	cout.flush();
}

void solve() {
	int n, m; cin >> n >> m;
	n--, m--;
	int r1 = query(0, 0), r2 = query(n, m), r3 = query(0, m);
	// y = x - r1
	// y = x - n - m + r2
	// y = -x + (n - r3)

	if (r1 == 0) { ans(0, 0); return; } 
	if (r2 == 0) { ans(n, m); return; } 
	if (r3 == 0) { ans(0, m); return; } 

	int b1 = r1, b2 = n + m - r2, b3 = r3 - n; 
	pi i13, i23;	
	
	if ((b1 + b3) % 2) i13 = {-1, -1};
	else {
		i13.ss = (b1 + b3) / 2;
		if (i13.ss - b1 > n) i13.ff = -1;
		else i13.ff = b1 - i13.ss;
	}

	if ((b2 + b3) % 2) { i23 = {-1, -1};

	if (i13.ff == -1 && i23.ff == -1) cout << "erm" << endl;
	}
	else {
		i23.ss = (b2 + b3) / 2;
		if (i23.ss - b2 > n) i23.ff = -1;
		else i23.ff = b2 - i23.ss;
	}


//	cout << i13.ff << " " << i13.ss << endl;
//	cout << i23.ff << " " << i23.ss << endl;

	if (i13.ff != -1) { if (query(i13.ff, i13.ss) == 0) i23.ff = -1; }
	else if (i23.ff != -1) { if (query(i23.ff, i23.ss) == 0) i13.ff = -1; }


	if (i13.ff != -1) ans(i13.ff, i13.ss);
	else ans(i23.ff, i23.ss);
}

signed main() {
	int t; cin >> t;
	while (t--)
		solve();
}
	
