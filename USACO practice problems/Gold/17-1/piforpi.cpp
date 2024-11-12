#include <bits/stdc++.h>
#define int long long
#define nl " \n"
#define pi pair<int, int>
#define ff first
#define ss second

using namespace std;
const int mxn = 2e5;
pi a[mxn], b[mxn];
int ans[mxn];

void solve() {
	ifstream cin("piepie.in");
	ofstream cout("piepie.out");
	int n, d; cin >> n >> d;

	multiset<pi> ma, mb;
	for (int i = 0; i < n; i++)
		cin >> a[i].ss >> a[i].ff,
		ma.insert({a[i].ff, i});
	for (int i = 0; i < n; i++)
		cin >> b[i].ff >> b[i].ss,
		mb.insert({b[i].ff, i});

	fill(ans, ans + n + n, -1);
	queue<pi> t;
	
	for (int i = 0; i < n; i++)
		if (a[i].ff == 0) t.push({a[i].ss, 1}), ans[i] = 1, ma.erase({a[i].ff, i});
	for (int i = 0; i < n; i++)
		if (b[i].ff == 0) t.push({b[i].ss, -1}), ans[i + n] = 1, mb.erase({b[i].ff, i});

	//cout << endl;
	while (t.size()) {
		 auto m = t.front();
		 t.pop();
		
	//	 cout << m.ff << " " << m.ss << endl;
		 if (m.ss < 0) { 
			 m.ss *= -1;
			 auto l = ma.lower_bound({m.ff - d, -1}), r = ma.upper_bound({m.ff, n});
	//		 cout << (*l).ss << " " << (*r).ss << " " << (r == ma.end())<< endl;
			 for (auto i = l; i != r; i++)
				 ans[(*i).ss] = (m.ss) + 1,
				 t.push({a[(*i).ss].ss, ans[(*i).ss]});
			ma.erase(l, r);
		 } else {
			 auto l = mb.lower_bound({m.ff - d, -1}), r = mb.upper_bound({m.ff, n});
	//		 cout << (*l).ss << " " << (*r).ss << " " << (r == mb.end()) << endl;
			 for (auto i = l; i != r; i++) {
				 ans[(*i).ss+n] = (m.ss) + 1,
				 t.push({b[(*i).ss].ss, -ans[(*i).ss + n]});
			 }
			 mb.erase(l, r);
		 }
	//	cout << endl;
	}
			
	for (int i = 0; i < n; i++)
		cout << ans[i] << endl;
}

signed main() {
//	cin.tie(0)->sync_with_stdio(false);
	
	int t= 1;
	while (t--)
		solve();
}
	
