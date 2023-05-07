using namespace std;
#include <bits/stdc++.h>
#define int long long
#define nl '\n'

void solve() {
    int n; cin >> n;
    int cnt[n] = {};
    int all = 0;
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        for (int j = 0, k = (n - i) % n; j < n; j++, k = (k + 1 == n ? 0 : k + 1))
            if (s[j] & 1)
                cnt[k]++, all++;
    }

    int ans = INT_MAX;
    for (int i = 0; i < n; i++)
        ans = min(ans, (all - cnt[i]) + (n - cnt[i]));  

    cout << ans << nl;
    return;
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t; cin >> t;
    while (t--)
        solve();
}