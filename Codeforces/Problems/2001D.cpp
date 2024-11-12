#include <bits/stdc++.h>
#include <queue>
#define int long long
#define nl " \n"
#define pi pair<int, int>
#define ff first
#define ss second

using namespace std;
const int mxn = 3e5;
int a[mxn];
int n;



void solve() {
	cin >> n;
	set<int> alp;

	for (int i = 0; i < n; i++)
		cin >> a[i], alp.insert(a[i]);
	stack<int> b;
	set<int> bl;
	priority_queue<pi> mxt, mnt;

	for (int i = n - 1; i >= 0; i--) {
		if (!bl.count(a[i]))
			b.push(i);
		bl.insert(a[i]);
		if (bl.size() == alp.size()) break;
	}

	//cout << endl;

	for (int i = 0; i <= b.top(); i++)
		mxt.push({a[i], i}),
		mnt.push({-a[i], i});

	int l = 0;
	int m = 1; // 1 -> max, 0 -> min
	
	vector<int> ans;

	while (b.size()) {
		int r = b.top();
		int pb = (m ? mxt.top().ff : -mnt.top().ff);	

		//cout << l << " " << r << " " << pb << endl;
		ans.push_back(pb);
		bl.erase(pb);	

		//for (int x : bl) cout << x << " ";
		//cout << endl;

		for (int i = l; i < n; i++)
			if (a[i] == pb) {l = i + 1; break; }
		
		m ^= 1;
		
		while(b.size() && !bl.count(a[b.top()])) b.pop();
		if (!b.size()) break;
		for (int i = r + 1; i <= b.top(); i++)
			mxt.push({a[i], i}),
			mnt.push({-a[i], i});

		while (mxt.size() && (bl.count(mxt.top().ff) == 0 || mxt.top().ss < l)) mxt.pop();
		while (mnt.size() && (bl.count(-mnt.top().ff) == 0 || mnt.top().ss < l)) mnt.pop();
	}
	
	cout << ans.size() << endl;
	for (int x : ans)
		cout << x << " ";
	cout << endl;
}

signed main() {
	cin.tie(0)->sync_with_stdio(false);

	int t; cin >> t;
	while (t--)
		solve();
}
	
