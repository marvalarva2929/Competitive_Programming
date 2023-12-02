#include <bits/stdc++.h>
#define int long long
#define nl " \n"
#define pi pair<int, int>
#define ff first
#define ss second

using namespace std;
const int mxn = 2e5;
int a[mxn+1], t[mxn+1];
int n, c;

void solve() {
    cin >> n >> c;

    for (int i = 1; i <= n; i++)
        cin >> a[i];

    iota(t + 1, t + n + 1, 1);
    sort(t + 1, t + n + 1, [&](const int & f, const int & s) -> bool {
                return (f * c) - a[f] < (s * c) - a[s];
            });

    int cur = a[1];
    for (int i = 1; i <= n; i++) {
        int j = t[i];
        if (j == 1) continue;
        if (cur + a[j] < c * j) { cout << "NO" << nl; return; }
        cur += a[j];
    }
    
    cout << "YES" << nl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t; cin >> t;
    while (t--)
        solve();
}
