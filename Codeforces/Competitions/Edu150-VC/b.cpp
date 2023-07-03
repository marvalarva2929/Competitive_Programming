#include <bits/stdc++.h>
#define int long long
#define nl " \n"

using namespace std;

void solve() {
    string l, r; cin >> l >> r;

    if (l.size() > r.size()) swap(l, r);

    while (l.size() < r.size()) { l = '0' + l; };
    
    int ans = 0;

    for (int i = 0; i < l.size(); i++) {
        int diff = abs(r[i] - l[i]);

        if (diff > 0) {
            ans += diff;
            ans += 9 * (l.size() - i - 1);
            break;
        }
    }
    
    cout << ans << nl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t; cin >> t;
    while (t--)
        solve();
}
