using namespace std;
#include <bits/stdc++.h>
#define int long long
#define nl '\n'

void solve() {
    int x, y; cin >> x >> y;
    int ans = 0;
    if (y < x)  
        ans = x + y;
    else {
        // ans = (x + y)/2;
        ans = y - (((x + y)/2) % x);
    }

    // cout << ans << " mod " << x << " = " << ans % x << "\n" << y << " mod " << ans << " = " << y % ans << nl;
    cout << ans << nl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t; cin >> t;
    while (t--)
        solve();
}