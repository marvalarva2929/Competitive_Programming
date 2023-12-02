#include <bits/stdc++.h>
#define int long long
#define nl " \n"
#define ff first
#define ss second
#define pi pair<int, int>

using namespace std;
const int mxn = 2e5;
bool a[mxn];

void solve() {
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        char c; cin >> c;
        a[i] = (c == 'A');
    }
    
    int ans = 0;
    int cnt = 0;
    
    int j = 0;
    while (!a[j] && j < n - 1) j++;

    for (int i = j; i < n; i++) 
        if (!a[i]) ans += i - j, j = i;
    cout << ans << nl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t; cin >> t;
    while (t--)
        solve();
}
