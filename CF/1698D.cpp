using namespace std;
#include <bits/stdc++.h>
#define int long long
#define nl '\n'
#define flsh cout.flush()

bool query(int i, int j) {
    cout << "? " << i << " " << j << nl;
    flsh;
    vector<int> a(j - i + 1);

    for (int x = 0; x < (j - i + 1); x++)
        cin >> a[x];
    int cnt = 0;

    for (int ix : a)
        if (ix >= i && ix <= j)
            cnt++;

    return (cnt % 2);
}

void solve() {
    int n; cin >> n;
    int l = 1, r = n;
    while (l < r) {
        int m = (l + r) >> 1;
        if (query(l, m))
            r = m;
        else l = m + 1;
    }
    cout << "! " << l << nl;
    flsh;
    return;
}   

signed main() {
    // cin.tie(0)->sync_with_stdio(false);

    int t; cin >> t;
    while (t--)
        solve();
}