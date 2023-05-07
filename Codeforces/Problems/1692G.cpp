using namespace std;
#include <bits/stdc++.h>
#define int long long
#define nl '\n'

void solve() {
    int n, k; cin >> n >> k;
    int a[n] = {};
    for (int i = 0; i < n; i++)
        cin >> a[i];

    vector<int> b;
    for (int i = 0; i < n - 1; i++)
        if (a[i] >= 2 * a[i + 1])    
            b.push_back(i + 1);



    int ans = 0;
    for (int i = 0; i < n - k; i++) {
        auto f = upper_bound(b.begin(), b.end(), i);
        if (f == b.end()) {
            ans++;
            continue;
        }
        int ff = *f - i;
        if (!ff || ff > k)
            ans++;
    }

    cout << ans << nl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t; cin >> t;
    while (t--)
        solve();
}