#include <bits/stdc++.h>
#define int long long
#define nl " \n"
#define pi pair<int, int>
#define ff first
#define ss second

using namespace std;
const int mxn = 3e5;
pi a[mxn];

void solve() {
    int n, k; cin >> n >> k;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        a[i].ff = ((x - 1) % k) + 1;
        a[i].ss = -i;
    }
   
    sort(a, a + n);
    
    for (int i = n - 1; i >= 0; i--)
        cout << -(a[i].ss) + 1 << nl[i == 0];

}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t; cin >> t;
    while (t--)
        solve();
}
