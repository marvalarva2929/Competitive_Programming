using namespace std;
#include <bits/stdc++.h>
#define int long long
#define nl '\n'

void solve() {
    int n, x, y; cin >> n >> x >> y;
    int a[n] = {};
    int s = 0;
    for (int & i : a)
        cin >> i, s += i;

    if ((x + s) % 2 == y % 2)
        cout << "Alice" << nl;
    else cout << "Bob" << nl;
    

}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t; cin >> t;
    while (t--)
        solve();
}