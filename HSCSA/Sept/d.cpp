#include <bits/stdc++.h>
#define int long long
#define nl " \n"
#define pi pair<int, int>
#define ff first
#define ss second

using namespace std;

bool is2(int x) {
    while (!(x & 1)) {
        x /= 2;
    }
        
    return x == 1;
}

void solve() {
    int n; cin >> n;
    if (is2(n + 1))
        cout << "NO" << nl;
    else cout << "YES" << nl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);
    
    int t; cin >> t;
    while (t--)
        solve();

}
