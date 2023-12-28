#include <bits/stdc++.h>
#define int long long
#define pi pair<int, int>
#define ff first
#define ss second
#define nl " \n"

using namespace std;
const int mxn = 2e5;
int a[mxn], b[mxn+mxn+4];
int n, m;

void build() {
    for (int i = m - 1; i; i--)
        b[i] = gcd(b[i<<1], b[i<<1|1]);
}

int rng(int l, int r) {
    int ans = b[l + m]; 
    for (l += m, r += m; l < r; l>>=1, r>>=1) {
        if (l&1) ans = gcd(ans, b[l++]);
        if (r&1) ans = gcd(ans, b[--r]);
    }
    return ans;
}

void solve() {
    cin >> n, m = n - 1;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    if (n == 1) { cout << 1 << nl; return; }

    for (int i = m; i < m + m; i++)
        b[i] = abs(a[i - m] - a[i - m + 1]);
    build();

    int l = 0, r = 0;
    int ans = 0;
    
    //for (int i = 0; i < m + m; i++)
    //    cout << b[i] << nl[i == m + m -1];

    //while (true) {
    //    int l, r; cin >> l >> r;
    //    cout << rng(l, r) << nl;
    //}
    
    while (r < m) {
        r = max(l, r);
        while (r < m && rng(l, r + 1) > 1) r++;
        ans = max(ans, r - l);
        l++;
    }
    cout << ans + 1 << nl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t; cin >> t;
    while (t--)
        solve();
}
