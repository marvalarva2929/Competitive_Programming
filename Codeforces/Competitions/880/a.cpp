#include <bits/stdc++.h>
#define int long long
#define nl '\n'

using namespace std;
const int mxn = 100;
int cnt[mxn+1];

void solve() {
    int n; cin >> n;
    memset(cnt, 0, sizeof cnt);

    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        cnt[x]++;
    }

    for (int i = 1; i <= 100; i++) {
        if (cnt[i - 1] < cnt[i]) {
            cout << "NO" << nl;
            return;
        }
    }

    cout << "YES" << nl;
    return;
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);
    
    int t; cin >> t;
    while (t--)
        solve();
}
