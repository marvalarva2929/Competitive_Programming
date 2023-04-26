using namespace std;
#include <bits/stdc++.h>
#define int long long
#define nl '\n'
#define pi pair<long long, long long>

void solve() {
    int n; cin >> n;
    int a[n] = {}, b[n] = {};
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];

    pi lo = {a[0] - b[0], 0}, hi = {a[0] + b[0], 0};
    for (int i = 1; i < n; i++)
        lo = min(lo, {a[i] - b[i], i}), hi = max(hi, {a[i] + b[i], i});

    cout << fixed << (double)(a[lo.second] + a[hi.second])/2 + (double)(b[hi.second] - b[lo.second])/2 << nl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t; cin >> t;
    while (t--)
        solve();
}