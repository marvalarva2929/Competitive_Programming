#include <bits/stdc++.h>
#define int long long
#define nl '\n'

using namespace std;
const int mxn = 1e5;
int a[mxn+1];

void solve() {
    int n; cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    for (int i = 1; i <= n; i++)
        a[i] ^= a[i - 1];

    set<int> cur;
    cur.insert(0);
    int ans = n;

    for (int i = 1; i <= n; i++) {
        if (cur.count(a[i]))
            ans--,
            cur.clear();

        cur.insert(a[i]);
    }
    
    cout << ans << nl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t; cin >> t;
    while (t--)
        solve();
}
