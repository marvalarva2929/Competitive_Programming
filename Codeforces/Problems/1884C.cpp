#include <bits/stdc++.h>
#define int long long
#define pi pair<int, int>
#define ff first
#define ss second
#define nl " \n"

using namespace std;
const int mxn = 1e5;
pi a[mxn];

void solve() {
    int n, m; cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> a[i].ff >> a[i].ss;
    sort(a, a + n);
    int ans = 0;

    {
        vector<pi> ev;
        int cnt = 0;
        for (int i = 0; i < n; i++)
            if (a[i].ff != 1) ev.push_back({a[i].ff, -1}), ev.push_back({a[i].ss, 1}); 
    
        sort(ev.begin(), ev.end());
        for (auto [_, i] : ev)
            cnt -= i,
            ans = max(ans, cnt);
    }
    
    {
        vector<pi> ev;
        int cnt = 0;
        for (int i = 0; i < n; i++)
            if (a[i].ss != m) ev.push_back({a[i].ff, -1}), ev.push_back({a[i].ss, 1}); 
    
        sort(ev.begin(), ev.end());
        for (auto [_, i] : ev)
            cnt -= i,
            ans = max(ans, cnt);
    }

    cout << ans << nl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t; cin >> t;
    while (t--)
        solve();
}
