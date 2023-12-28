#include <bits/stdc++.h>
#define int long long
#define pi pair<int, int>
#define ff first
#define ss second
#define nl " \n"

using namespace std;
const int mxn = 2e5;
int a[mxn], b[mxn];

void solve() {
    int n; cin >> n;
    int mx = INT_MIN, mn = INT_MAX;
    int ans = 0;

    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];
    
    for (int i = 0; i < n; i++) {
        if (b[i] < a[i]) swap(b[i], a[i]);
        ans += b[i] - a[i];
    
        mx = max(mx, a[i]);
        mn = min(mn, b[i]);
    }
    
    cout << max(ans, ans + ((mx - mn)<<1)) << nl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t; cin >> t;
    while (t--)
        solve();
}
