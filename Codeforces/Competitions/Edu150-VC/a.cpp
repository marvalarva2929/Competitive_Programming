#include <bits/stdc++.h>
#define int long long
#define nl " \n"

using namespace std;

const int mxn = 100;
int a[mxn];

void solve() {
    int n; cin >> n;
    int cnt = 0;

    for (int i = 0; i < n; i++)
        cin >> a[i], cnt += (a[i] == -1);

    if (cnt % 2 == 0 && cnt <= n/2) {
        cout << 0 << nl;
        return;
    }
    
    int need = (cnt % 2);
    for (int i = cnt - need; i >= 0; i -= 2) {
        if (i <= n/2) {cout << cnt - i << nl; return; }
    }
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t; cin >> t;
    while (t--)
        solve();
}
