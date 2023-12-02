#include <bits/stdc++.h>
#define int long long
#define pi pair<int, int>
#define nl " \n"
#define ff first
#define ss second

using namespace std;
const int mxn = 500;
int a[mxn];

void solve() {
    int n; cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (a[j] < a[i]) {
                cout << 0 << nl;
                return;
            }
    
    int ans = INT_MAX;
    for (int i = 0; i < n - 1; i++)
        ans = min(ans, (a[i + 1] - a[i])/2 + 1);
    
    cout << ans << nl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t; cin >> t;
    while (t--)
        solve();
}
