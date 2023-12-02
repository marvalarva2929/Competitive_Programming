#include <bits/stdc++.h>
#define int long long
#define pi pair<int, int>
#define ff first
#define ss second
#define nl " \n"

using namespace std;
int n, k, x, y; 
const int mxn = 2e5;
pi a[mxn];

int dist(int i, int j) {
    return abs(a[i].ff - a[j].ff) + abs(a[i].ss - a[j].ss);
}

void solve() {
    cin >> n >> k >> x >> y;
    --x, --y;
    for (int i = 0; i < n; i++)
       cin >> a[i].ff >> a[i].ss; 
    
    int ans = dist(x, y);
    
    int mna = LLONG_MAX, mnb = LLONG_MAX;
    for (int i = 0; i < k; i++)
        mna = min(mna, dist(x, i)),
        mnb = min(mnb, dist(y, i));
    
    ans = min(ans, (k ? mna + mnb : LLONG_MAX));
    
    cout << ans << nl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t; cin >> t;
    while (t--)
        solve();
}
