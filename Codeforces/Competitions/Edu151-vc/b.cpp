#include <bits/stdc++.h>
#define int long long
#define nl " \n"

using namespace std;

void solve() {
    int a[2], b[2], c[2];

    cin >> a[0] >> a[1] >> b[0] >> b[1] >> c[0] >> c[1];
    
    int ans = 1;
    
    for (int i = 0; i < 2; i++)
        if ((b[i] >= a[i] && c[i] >= a[i]) || (b[i] <= a[i] && c[i] <= a[i]))
            ans += min(abs(a[i] - b[i]) , abs(a[i] - c[i]) );
 
    cout << ans << nl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t; cin >> t;
    while (t--)
        solve();
}
