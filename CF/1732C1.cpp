using namespace std;
#include <bits/stdc++.h>
#define int long long
#define nl '\n'
#define no "no"
#define yes "yes"
#define pr1int(x, y, z) for1 (int i = y; i <= z; i++) {cout << x[i] << " ";} cout << nl;

const int mxn = (int)1e5 + 10;

int x[mxn] = {};
int s[mxn] = {};

int f(int l, int r) {
    return ((s[r] - s[l - 1]) - (x[r] ^ x[l - 1]));
}

void solve() {
    int n, q; cin >> n >> q;
    int curx = 0, curs = 0;
    
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        curs += a;
        curx ^= a;
        x[i + 1] = curx;
        s[i + 1] = curs;
    }

    int l, r; cin >> l >> r;

    pair<int, int> ans = {l, r};

    // for (int i = l; i < n; i++) { // binary search
    //     int l1 = i, r1 = n;
    //     while (r1 > l1) {
    //         int m = (l1 + r1) >> 1;
    //         if (f(i, m) == f(1, n))
    //             r1 = m;
    //         else l1 = m + 1;
    //     }
    //     if (f(i, r1) == f(1, n) && i <= r1 && r1 - i < ans.second - ans.first)
    //         ans = {i, r1};
    // }

    for (int i = n - 1; i >= 1; i--) { // two (ish) pointers
        if (i > r) continue;
        while (i < r && f(i, r - 1) == f(1, n))
            r--;
        if (f(i, r) == f(1, n) && r - i < ans.second - ans.first)
            ans = {i, r};
    }

    cout << ans.first <<" " << ans.second << nl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t; cin >> t;
    while (t--)
        solve();
}