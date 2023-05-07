using namespace std;
#include <bits/stdc++.h>
#define int long long
#define nl '\n'

void solve() {
    int n; cin >> n;
    string s, t; cin >> s >> t;

    int x = 0, y = 0, z = 0;
    int ans = INT_MAX;

    for (int i = 0; i < n; i++)
        x += (s[i] & 1), y += (t[i] & 1), z += (s[i] != t[i]);

    if (x == y)
        ans = z;
    
    if (x == n - y + 1)
        ans = min(ans, n - z);

    cout << (ans == INT_MAX ? -1 : ans) << nl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t; cin >> t;
    while (t--)
        solve();
}