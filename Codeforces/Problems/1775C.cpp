using namespace std;
#include <bits/stdc++.h>
#define int long long
#define nl '\n'

void solve() {
    int n, x; cin >> n >> x;
    if (x > n) {cout << -1 << nl; return; }

    if (n == x) {
        cout << n << nl; 
        return;
    }

    set<int> pv;

    int m = n;
    int i = 0;
    while (m) {
        while (!((m >> i) & 1)) i++;
        while ((m >> i) & 1) m -= (m&-m), i++;
        pv.insert(m);
    }

    if (pv.find(x) == pv.end()) {
        cout << -1 << nl;
        return;
    }

    int diff = n - x;
    cout << fixed << x + (int)pow(2, (int)log2(diff) + 1) << nl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);
        
    int t; cin >> t;
    while (t--)
        solve();
}