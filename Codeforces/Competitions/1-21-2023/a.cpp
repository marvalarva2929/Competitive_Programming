using namespace std;
#include <bits/stdc++.h>
#define int long long
#define nl '\n'

void solve() {
    int n; cin >> n;
    int a[n] = {};
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int b = a[0] % 2;
    int ans = 0;
    int i = 0;

    while (i < n) {
        int j = i + 1;
        while (a[j] % 2 == a[i] % 2 && j < n) j++;
        ans += j - i - 1; 
        i = j;
    }

    cout << ans << nl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t; cin >> t;
    while (t--)
        solve();
}