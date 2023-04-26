using namespace std;
#include <bits/stdc++.h>
#define int long long
#define nl '\n'
#define pi pair<int, int>
#define pii pair<int, pi>
#define inf LONG_LONG_MAX

struct flight {
	int to, arrive, depart;
	flight(int b, int c, int d) {
		depart = b, to = c, arrive = d; 
	}
	friend bool operator<(const flight & a, const flight & b) {
		return a.depart < b.depart;
	}
};	


const int mxn = 2e5 + 10;
int ans[mxn];
int a[mxn];
int id[mxn];
vector<flight> flights[mxn];

signed main() {
	int n, m; cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int c, r, d, s; cin >> c >> r >> d >> s;
		flights[c].push_back(flight(r, d, s));
	}
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	a[1] = 0;

	for (int i = 1; i <= n; i++)
		for (flight & f : flights[i])
			f.depart -= a[i];

	for (int i = 1; i <= n; i++)
		sort(flights[i].begin(), flights[i].end());
	
	queue<flight> nextFlight;
	fill(ans + 2, ans + n + 1, inf);

	for (flight f : flights[1])
		nextFlight.push(f);

	while (nextFlight.size()) {
		auto cur = nextFlight.front();
		nextFlight.pop();
		ans[cur.to] = min(ans[cur.to], cur.arrive);
		while (flights[cur.to].size() 
				&& 
			flights[cur.to].back().depart >= cur.arrive) {
		
			nextFlight.push(flights[cur.to].back());
			flights[cur.to].pop_back();
		}
	}

	for (int i = 1; i <= n; i++)
		cout << (ans[i] == inf ? -1 : ans[i]) << nl;
}
