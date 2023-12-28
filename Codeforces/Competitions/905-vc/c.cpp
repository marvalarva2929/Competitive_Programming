#include <bits/stdc++.h>
#define int long long
#define nl " \n"
#define ff first
#define ss second
#define pi pair<int, int>

using namespace std;
const int mxn = 1e5;
int a[mxn], b[mxn], c[mxn];

void solve() {
    int n; cin >> n;
    
    map<int, int> f, s;
    fill(b, b + n, 0);
    fill(c, c + n, 0);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (!f[a[i]]) f[a[i]] = i + 1;
        s[a[i]] = i + 1; 
    }
    
    for (auto [m, l] : f)
        b[l - 1]++;
    for (auto [m, l] : s)
        c[l - 1]++;
    
    int sb = 0, sf = 0;

    for (int i = n - 1; i >= 0; i--)
        sb += c[i];

    int ans = 0;
    for (int i = 0; i < n; i++) {
        sf += b[i];
        if (c[i]) ans +=  sf;
    }
    
    cout << ans << nl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t; cin >> t;
    while (t--)
        solve();
}
