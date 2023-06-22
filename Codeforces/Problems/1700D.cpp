#include <bits/stdc++.h>
#define int long long
#define nl " \n"

using namespace std;

const int mxn = 2e5;
int a[mxn];

void solve() {
     int n; cin >> n;
     int s = 0;
     for (int i = 0; i < n; i++)
         cin >> a[i],
         s += a[i];
    
    int cur = 0, off = 0;

    for (int i = 0; i < n; i++) {
        int flow = cur + off;
        int req = a[i] - flow;
        if (req > 0) {
            int inc = (req + i) / (i + 1);
            cur += inc;
            off = -(a[i] - (flow + ((i + 1) * inc)));
        } else off = -req;
    }
    
    int q; cin >> q;
    while (q--) {
        int x; cin >> x;
        if (x < cur) { cout << -1 << nl; continue; } 
        int ans = (s + x - 1) / x;
        cout << ans << nl;
    }
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t = 1; 
    while (t--)
        solve();
}
