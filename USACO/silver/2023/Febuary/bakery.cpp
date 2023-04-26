using namespace std;
#include <bits/stdc++.h>
#define int long long
#define nl '\n'
#define max(x, y) (int)max((int)x, (int)y)
const int mxn = 110;

int A[mxn];
int B[mxn];
int CC[mxn];
int n, C, M;

bool check(int w) {
	int d = C + M - w;
	int mxx = min(C, d - 1),
	    mnx = max(1, C - w);

	for (int i = 0; i < n; i++) {
		int a = A[i], b = B[i], c = CC[i];
		if (a > b) {
			mxx = min(mxx, (c - (b * d))/(a - b));
		} else if (a < b) {
			mnx = max(mnx, (-c + (b * d) + (b - a - 1))/(b - a));
		} else if (a * d > c) {
			return false;
		}
	}
	return mnx <= mxx;
}

void solve() {
	cin >> n >> C >> M;
	for (int i = 0; i < n; i++) 
		cin >> A[i] >> B[i] >> CC[i];
	int l = 0, r = C + M - 2;
	while (r > l) {
		int m = (l + r) >> 1;
		bool ans = check(m);
		if (ans)
			r = m;
		else l = m + 1;
	}
	cout << r << nl;
}

signed main() {
	cin.tie(0)->sync_with_stdio(false);
	int t; cin >> t;
	while (t--)
		solve();
}
