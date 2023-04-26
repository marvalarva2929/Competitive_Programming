using namespace std;
#include <bits/stdc++.h>
#define int long long
#define nl '\n'

void solve() {
    int n, x, y; cin >> n >> x >> y;
    bool a[n] = {}, b[n];
    for (int i = 0; i < n; i++) {
        char c; cin >> c;
        a[i] = c&1;
    }
    for (int i = 0; i < n; i++) {
        char c; cin >> c;
        b[i] = c&1;
    }

    vector<int> diff;
    for (int i = 0; i < n; i++)
        if (a[i] != b[i])
            diff.push_back(i);
    
    if (diff.size() % 2) {
        cout << -1 << nl;
        return;
    } 

    int ans = 0;

    for (int i = 0; i < diff.size()/2; i++) {
        // cout << diff[i] << " " << diff[i + diff.size()/2] << nl;
        if (diff[i] + 1 == diff[i + diff.size()/2])
            ans += min(x, 2 * y);
        else ans += y;
    }

    cout << ans << nl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);
    
    int t; cin >> t;
    while (t--)
        solve();
}