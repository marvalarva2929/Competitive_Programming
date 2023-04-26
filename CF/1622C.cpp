using namespace std;
#include <bits/stdc++.h>
#define int long long
#define nl '\n'

int accurateFloor(int a, int b) {
	int val = a / b;
	while (val * b > a)
		val--;
	return val;
}

void solve() {
    int n, k; cin >> n >> k;
    int a[n] = {}, p[n + 1] = {};
    
    for (int i = 0; i < n; i++)
        cin >> a[i];
    
    sort(a, a + n);


    for (int i = 0; i < n; i++)
        p[i + 1] = p[i] + a[i];
    
    int ans = INT_MAX;

	for (int y = 0; y < n; y++) {
		
		int x = a[0] - accurateFloor(k - p[n - y] + a[0], y + 1);
		ans = min(ans, y + max(0LL, x));
	}

    cout << ans << nl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t; cin >> t;
    while (t--)
        solve();
}