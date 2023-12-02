#include <bits/stdc++.h>
#define int long long
#define nl " \n"
#define ff first
#define ss second
#define pi pair<int, int>

using namespace std;
const int mxn = 10;
int a[mxn];

void solve() {
    int n; cin >> n;      
    for (int i = 0; i < n; i++)
        cin >> a[i];

    cout << (a[0] == 1 ? "YES" : "NO") << nl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t; cin >> t;
    while (t--)
        solve();
}
