#include <bits/stdc++.h>
#define int long long
#define nl " \n"
#define pi pair<int, int>
#define ff first
#define ss second

using namespace std;

bool can(int a, int b, int c) {
    return (b + c) % 2 == 0;
}

void solve() {
    int a, b, c; cin >> a >> b >> c;

    cout << can(a, b, c) << " " << can(b, c, a) << " " << can(c, b, a) << nl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t; cin >> t;
    while (t--)
        solve();
}
