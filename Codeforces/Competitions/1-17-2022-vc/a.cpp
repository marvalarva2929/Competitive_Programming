using namespace std;
#include <bits/stdc++.h>
#define int long long
#define nl '\n'

void solve() {
    int w, d, h, a, b, f, g; cin >> w >> d >> h >> a >> b >> f >> g;

    int o = abs(a - f) + g + b + h;
    int t = abs(a - f) + abs(d - g) + abs(d - b) + h;
    int e = abs(b - g) + a + f + h;
    int ff = abs(b - g) + abs(w - a) + abs(w - f) + h;

    // cout << o << " " << t << " " << ff << " " << e << nl;

    cout << min(min(o, t), min(ff, e)) << nl;
    return;
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t; cin >> t;
    while (t--)
        solve();
}