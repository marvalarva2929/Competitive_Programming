using namespace std;
#include <bits/stdc++.h>
#define int long long
#define nl '\n'

void solve() {
    int a, b, x; cin >> a >> b >> x;

    if (a < b)
        swap(a, b);

    while (a > x && b > 0) {
        int left = a % b;
        if ((x - left) % b == 0) a = x;
        else a = left;
        swap(a, b);
    }

    if (a == x || b == x)
        cout << "YES" << nl;
    else cout << "NO" << nl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t; cin >> t;
    while (t--)
        solve();
}