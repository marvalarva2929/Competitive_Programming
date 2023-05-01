using namespace std;
#include <bits/stdc++.h>
#define int long long
#define nl '\n'

const int mxn = 3e5;
int a[mxn];

void solve() {
	int n; cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	bool no = true;
	for (int i = 0; i < n; i++)
		no &= a[i] == 0;
	
	if (no) {
		cout << "No" << nl;
		return;
	}
	
	int cur = 0;
	vector<int> pos, neg, zer;
	for (int i = 0; i < n; i++) {
		if (a[i] > 0)
			pos.push_back(a[i]);
		else if (a[i] < 0)
			neg.push_back(a[i]);
		else zer.push_back(a[i]);
	}

	vector<int> ans;
	for (int z : zer)
		ans.push_back(z);
	
	for (int i = 0; i < (n - zer.size()); i++) {
		if (cur <= 0)
			ans.push_back(pos.back()),
			pos.pop_back();
		else 
			ans.push_back(neg.back()),
			neg.pop_back();
		cur += ans.back();
	}
	
	cout << "Yes" << nl;
	for (int i : ans)
		cout << i << " ";
	cout << nl;
			
}

signed main() {
	cin.tie(0)->sync_with_stdio(false);

	int t; cin >> t;
	while (t --> 0)
		solve();
}
