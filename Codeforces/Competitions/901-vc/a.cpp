#include <bits/stdc++.h>
#define int long long
#define nl " \n"
#define pi pair<int, int>
#define ff first
#define ss second

using namespace std;
const int mxn = 100;
int a[mxn];

void solve() {
    int aa, b, n; cin >> aa >> b >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n);
    
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans += b - 1, b = 1;
    
        b += a[i]; b = min(b, aa);
    }
    
    cout << ans + (b - 1) + 1 << nl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t; cin >> t;
    while (t--)
        solve();
}
