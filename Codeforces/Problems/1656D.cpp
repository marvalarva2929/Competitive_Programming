#include <bits/stdc++.h>
#define int long long
#define nl " \n"

using namespace std;

void solve() {
    int n; cin >> n;
    int t = n;

    if (n % 2) { cout << 2 << nl; return; };

    while (n) {
        if ((n % 2) && n != 1) {
            cout << min(2 * t / n, n) << nl;        
            return; 
        }
        n >>= 1; 
    }
    
    cout << -1 << nl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);
    
    int t; cin >> t;
    while (t--)
        solve();
}
