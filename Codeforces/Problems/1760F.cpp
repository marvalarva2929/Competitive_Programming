using namespace std;
#include <bits/stdc++.h>
#define nl '\n'
#define int long long
#define MAX (int)2e5 + 10

void solve() {
    int n, c, d; cin >> n >> c >> d;
    int mx = 0, sm = 0;
    int a[n] = {};
    
    for (int i = 0; i < n; i++) 
        cin >> a[i], sm += a[i], mx = max(mx, a[i]);

    if (mx * d < c) {
        cout << "Impossible" << nl;
        return;
    }

    sort(a, a + n, greater<int>());

    int pref[n + 1] = {};

    for (int i = 1; i <= n; i++)
        pref[i] = pref[i - 1] + a[i - 1];

    if (pref[min(n, d)] >= c) {
        cout << "Infinity" << nl;
        return;
    }


    int l = 0, r = d;
    while (l < r) {
        int k = (l + r)/2;
        int mn = (pref[min(n, k + 1)] * (d / (k + 1))) + pref[min(n, d % (k + 1))];
        if (mn < c)
            r = k;
        else 
            l = k + 1;
    }

    cout << --l << nl;

}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    int t; cin >> t;

    while (t--)
        solve();
}