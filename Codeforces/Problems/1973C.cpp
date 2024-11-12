#include <bits/stdc++.h>
#define int long long
#define nl " \n"
#define pi pair<int, int>
#define ff first
#define ss second

using namespace std;
const int mxn = 1e5;
int a[mxn], b[mxn];

void solve() {
	int n; cin >> n;
	int idx = -1;
	for (int i = 0; i < n; i++)
		cin >> a[i], idx = (a[i] == n ? i : idx);

	vector<pi> p;
	vector<pi> q;
	
	for (int i = 0; i < n; i++) {
		if ((i % 2) == (idx % 2)) p.push_back({a[i], i});	
		else q.push_back({a[i], i});
	}

	sort(p.begin(), p.end());
	sort(q.begin(), q.end(), greater<pi>());
	
	
	int d = n;
	for (auto & c : p) 
		b[c.ss] = d--;

	d = 1;
	for (auto & c : q)
		b[c.ss] = d++;

	for (int i = 0; i < n; i++)
		cout << b[i]  << " \n"[i == n - 1];
}

signed main() {
	cin.tie(0)->sync_with_stdio(false);

	int t; cin >> t;
	while (t--)
		solve();
}
	
