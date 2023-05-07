using namespace std;
#include <bits/stdc++.h>
#define int long long
#define nl '\n'

void solve() {
    int n, k; cin >> n >> k;
    int a[n] = {}, mns[n] = {};

    for (int i = 0; i < n; i++)
        cin >> a[i];

    mns[n - 1] = a[n - 1];

    for (int i = n - 2; i >= 0; i--)
        mns[i] = min(mns[i + 1], a[i]);

    int ans = 0, mn = INT_MAX;
    set<int> fix;
    for (int i = 0; i < n; i++)
        if (a[i] > mns[i] || a[i] > mn)
            fix.insert(a[i]), mn = min(mn, a[i]);

    cout << ceil((double)fix.size()/k) << nl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t; cin >> t;
    while (t--)
        solve();
}