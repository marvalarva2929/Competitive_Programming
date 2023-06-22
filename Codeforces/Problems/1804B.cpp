#include <bits/stdc++.h>
#define int long long
#define nl " \n"

using namespace std;
const int mxn = 2e5; 

void solve() {
    int n, k, d, w; cin >> n >> k >> d >> w;
    int ans = 0, exp = d, rem = k;
    
    vector<int> a(n);

    for (int i = 0; i < n; i++) cin >> a[i];

    int idx = 0;
    while (idx < n) {
        ans++;
        int nx = a[idx] + d + w;
        int nidx = upper_bound(a.begin(), a.end(), nx) - a.begin();
        idx = min(idx + k, nidx);
    }
    
    cout << ans << nl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t; cin >> t;
    while (t--)
        solve();
}
