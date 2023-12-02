#include <bits/stdc++.h>
#define int long long
#define pi pair<int, int>
#define ff first
#define ss second
#define nl " \n"

using namespace std;
const int mxn = 2e5;
int a[mxn];

void solve() {
    int n; cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    
    int mn = 0, mx = 0;
    int s = 0;

    for (int i = 0; i < n; i++)
        s += a[i], mn = min(mn, s), mx = max(mx, s);

    cout << (mx - mn) << nl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t; cin >> t;
    while (t--)
        solve();
}
