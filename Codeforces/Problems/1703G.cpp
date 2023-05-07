using namespace std;
#include <bits/stdc++.h>
#define int long long
#define nl '\n'

void solve() {
    int n, x; cin >> n >> x;
    int a[n] = {}, pref[n + 1] = {};
    for (int i = 0; i < n; i++)
        cin >> a[i];
    
    for (int i = 0; i < n; i++)
        pref[i + 1] = pref[i] + a[i];

    int ans = 0;
    for (int i = 0; i <= n; i++) {
        int og = pref[i] - (i * x);
        for (int j = i; j < min(n, i + 40); j++) {
            og += (a[j] >> (j - i + 1));
        }
        ans = max(ans, og);
    }
    cout << ans << nl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t; cin >> t;
    while (t--)
        solve();
}