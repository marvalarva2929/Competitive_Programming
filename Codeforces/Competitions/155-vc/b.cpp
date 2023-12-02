#include <bits/stdc++.h>
#define int long long
#define nl " \n"
#define pi pair<int, int>
#define ff first
#define ss second

using namespace std;
const int mxn = 3e5;
int a[mxn], b[mxn];

void solve() {
    int n; cin >> n;
    int mna = INT_MAX, mnb = INT_MAX;
    int sa = 0, sb = 0;

    for (int i = 0; i < n; i++)
        cin >> a[i], mna = min(mna, a[i]), sa += a[i];

    for (int i = 0; i < n; i++)
        cin >> b[i], mnb = min(mnb, b[i]), sb += b[i];

    cout << min((n * mna) + sb, (n * mnb) + sa) << nl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t; cin >> t;
    while (t--)
        solve();
}

