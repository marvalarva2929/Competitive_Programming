using namespace std;
#include <bits/stdc++.h>
#define int long long
#define nl '\n'
#define pi pair<int, int>

void solve() {
    int n, c; cin >> n >> c;
    pi a[n] = {};
    vector<int> pref;
    int ans = 0;

    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        a[i] = {x + min(n - i, i + 1), x + i + 1};
    }

    // cout << 'e' << nl;

    sort(a, a + n);
    
    pref.push_back(0);
    for (int i = 0; i < n; i++)
        pref.push_back(pref.back() + a[i].first);

    // cout << 'e' << nl;

    for (int i = 0; i < n; i++) {
        int cc = c - a[i].second;
        int l = 0, r = n;
        int mx = 0;
        while (l <= r) {
            int m = l + (r - l)/2;
            int price = pref[m];
            int teleporters = m + 1;
            if (i < m)
                price -= a[i].first,
                teleporters--;
            
            // cout << i << " : " << l << " " << r << " " << price << nl;


            if (price <= cc) {
                l = m + 1;
                mx = max(mx, teleporters);  
            } else r = m - 1;
        }
        ans = max(ans, mx);
    }
    
    cout << ans << nl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);
    // cout << nl;
    int t; cin >> t;
    while (t--)
        solve();
}