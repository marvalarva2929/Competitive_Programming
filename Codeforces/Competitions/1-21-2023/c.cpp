using namespace std;
#include <bits/stdc++.h>
#define int long long
#define nl '\n'
#define MAX (int)1e5 + 10
int ld[MAX];

set<int> factorize(int a) {
    set<int> ret;
    ret.insert(a);
    while (a != 1)   
        a /= ld[a], ret.insert(a), ret.insert(ld[a]);
    return ret;
}

void solve() {
    int n, m; cin >> n >> m;
    int a[n] = {};
    vector<int> in[MAX] = {};

    for (int i = 0; i < n; i++)
        cin >> a[i];

    for (int i : a) {
        // cout << i << " :" << nl;
        for (int j : factorize(i))
            in[j].push_back(i);
        // cout << nl;
    }

    int hi = 0, lo = INT_MAX; // FIND THE MAX MIN, AND THE MIN MAX

    for (int i = m/2 + 1; i <= m; i++) {
        int mn = INT_MAX, mx = INT_MIN;
        for (int j : in[ld[i]])
            mn = min(j, mn), mx = max(mx, j);

        if (in[ld[i]].empty()) {
            cout << -1 << nl;
            return;
        }

        hi = max(hi, mn);
        lo = min(mx, lo);

        // cout << i << " " << mn << " " << mx << nl;
    }

    cout << max((int)0, hi -  lo) << nl;
    return;
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    for (int i = 2; i < MAX; i += 2)
        ld[i] = 2;

    for (int i = 3; i < MAX; i += 2) {
        if (!ld[i])
            for (int j = i; j < MAX; j += i)
                if (!ld[j])
                    ld[j] = i;
    }

    int t; cin >> t;
    while (t--)
        solve();
}