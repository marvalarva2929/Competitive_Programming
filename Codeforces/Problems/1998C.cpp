#include <bits/stdc++.h>
#define int long long
#define nl " \n"
#define pi pair<int, int>
#define ff first
#define ss second

using namespace std;
const int mxn = 2e5;
pi a[mxn];

void solve(int t) {
	int n, k; cin >> n >> k;

	for (int i = 0; i < n; i++)
		cin >> a[i].ff;
	for (int i = 0; i < n; i++)
		cin >> a[i].ss;

	sort(a, a + n);	


	int nmd = 0;
	int ans1 = a[n - 1].ff;
	for (int i = n - 1; i >= 0; i--)
		if (a[i].ss) {
			ans1 = a[i].ff + k;	

			vector<int> p;
			for (int j = 0; j < n; j++)
				if (j != i)
					p.push_back(a[j].ff);
			nmd = p[((p.size()+1)/2)-1];
			break;
		}
	


	int l = a[(n/2) - 1].ff, r = a[n - 1].ff;
	
	while (l + 1 < r) {
		int m = (l + r) >> 1;

		bool check = 1;
		
		vector<int> p;
		int h = ((n-1)/2) + 1;	
		for (int i = 0; i < n - 1; i++) {
			if (a[i].ff >= m) h--;
			else if (a[i].ss == 1) p.push_back(a[i].ff);
		}

		int rm = 0;
		sort(p.begin(), p.end(), greater<int>());
		if (h > p.size()) check = 0;
		else {
			for (int i = 0; i < h; i++)
				rm += m - p[i];
		}

		if (rm > k) check = 0;
		
		if (check) l = m;
		else r = m;
	}
	
	cout << (int)max((int)ans1 + nmd, (int)l + a[n - 1].ff) << endl;
}

signed main() {
	cin.tie(0)->sync_with_stdio(false);
	
	int t; cin >> t;
	for (int i = 0; i < t; i++)
		solve(i + 1);
}
	
