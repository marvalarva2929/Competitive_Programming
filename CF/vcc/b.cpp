using namespace std;
#include <bits/stdc++.h>
#define int long long
#define nl '\n'

void solve() {
    int a, b, c, d; cin >> a >> b >> c >> d;
    int ans = a;

    int mn = min(b, c);

    if (a != 0) ans += mn * 2;

    if (a != 0) b -= mn, c -= mn;

    if (b) {
        int m = min(a, b);
        a -= m;
        b -= m;
        ans += m;
    } else if (c) {
        int m = min(a, c);
        a -= m;
        c -= m;
        ans += m;
    }

   int md = min(a + 1, d);
    d -= md;
    ans += md;
    a -= md;

    if (b && a >= 0) {
        int mb = min(a + 1, b);
        a -= mb;
        b -= mb;
        ans += mb;
    } 

    if (c && a >= 0) {
        int mc = min(a + 1, c);
        a -= mc;
        b -= mc;
        ans += mc;
    }



    cout << ans << nl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t; cin >> t;
    while (t--)
        solve();
}