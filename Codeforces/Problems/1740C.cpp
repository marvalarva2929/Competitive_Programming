using namespace std;
#include <bits/stdc++.h>
#define int long long
#define nl '\n'

void solve() {
    int n; cin >> n;
    int a[n] = {};
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n);
    int add1 = INT_MIN;
    int add2 = INT_MIN;

    for (int i = 0; i < n - 1; i++) 
        add1 = max(add1, abs(a[i] - a[i + 1]) + abs(a[i] - a[n - 1]));
    for (int i = 2; i < n; i++)
        add2 = max(add2, abs(a[i] - a[i - 1]) + abs(a[i] - a[0]));

    cout << max(add1, add2) << nl;   
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t; cin >> t;
    while (t--)
        solve();
}