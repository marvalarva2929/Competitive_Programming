#include <bits/stdc++.h>
#define int long long
#define nl " \n"
#define ff first
#define ss second
#define pi pair<int, int>

using namespace std;
const int mxn = 2e5;
pi a[mxn], b[mxn];
int sa[mxn];
int ans[mxn];

void solve() {
    int n, x; cin >> n >> x;
    for (int i = 0; i < n; i++) {
        int y; cin >> y; 
        a[i] = {y, i}; 
    }
    for (int i = 0; i < n; i++) {
        int y; cin >> y; 
        b[i] = {y, i}; 
    }
    
    iota(sa, sa + n, 0);

    sort(sa, sa + n, [](const int & f, const int & s) -> bool {
                return a[f].ff < a[s].ff;
            });

    for (int i = 0; i < n; i++)
        cout << sa[i] << nl[i == n- 1];

    sort(a, a + n);
    sort(b, b + n);
    
    reverse(a, a + n);

    for (int i = 0; i < x; i++) {
        ans[a[x - i - 1].ss] = b[i].ff;
    }
        
    reverse(a, a + n);

    for (int j = 0; j < n - x; j++) {
        ans[a[j].ss] = b[j + x].ff;
    }

    int y = 0;
    for (int i = 0; i < n; i++)
        y += a[i].ff > ans[a[i].ss];
    
    if (y != x) cout << "NO" << nl;
    else {
        cout << "YES" << nl;
        for (int i = 0; i < n; i++)
            cout << ans[i] << nl[i == n - 1];
    }
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t; cin >> t;
    while (t--)
        solve();
}
