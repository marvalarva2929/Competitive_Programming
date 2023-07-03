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
    int n; cin >> n;
    int neg = 0;
    int mx = 0;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] < 0) neg = a[i];
        mx = max(mx, a[i]); 
    }
    
    if (neg) cout << neg << nl;
    else cout << mx << nl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t; 
    cin >> t;
    while (t--)
        solve();
}
