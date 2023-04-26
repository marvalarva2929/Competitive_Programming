using namespace std;
#include <bits/stdc++.h>
#define int long long
#define nl '\n'

void solve() {
    int n; cin >> n;
    int a[n] = {};

    unordered_map<int, int> cnt;

    for (int i = 0; i < n; i++)
        cin >> a[i];
    
    sort(a, a + n);
    for (int i : a)
        cnt[i]++;

    int ans = 0;

    for (int i = 1; i <= 100; i++)
        ans += min((int)cnt[i], (int)ceil((double)cnt[i]/2) * (int)i);

    cout << ans << nl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t; cin >> t;
    while (t-- )
        solve();
}