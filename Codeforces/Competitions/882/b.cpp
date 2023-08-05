#include <bits/stdc++.h>
#define int long long
#define nl " \n"
#define pi pair<int, int>
#define ff first
#define ss second

using namespace std;
const int mxn = 2e5;
int a[mxn];

void solve() {
    int n; cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int x = a[0];
    for (int i = 1; i < n; i++)
        x &= a[i];

    if (x != 0) cout << 1 << nl;
    else {
        int j = 0;
        while (j < n && a[j] == 0) j++;
        
        int cur = a[j];
        int ans = 0;
        for (int i = j; i < n; i++) {
            cur &= a[i];
            if (cur == 0) ans++, cur = ((i < n - 1) ? a[i + 1] : -1);
        }

        cout << ans + j << nl; 
    }
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t; cin >> t;
    while (t--)
        solve();
}
