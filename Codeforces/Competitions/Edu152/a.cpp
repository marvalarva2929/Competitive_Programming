#include <bits/stdc++.h>
#define int long long
#define nl " \n"
#define pi pair<int, int>
#define ff first
#define ss second

using namespace std;

void solve() {
    int b, c, h; cin >> b >> c >> h;
    int k = c + h;
    
    int ans = 0;
    for (int i = 1; i <= b; i++) {
        if (i - 1 > k) break;
        ans = max(ans, i + i - 1);
    }
    
    cout << ans << nl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t; cin >> t;
    while (t--)
        solve();
}
