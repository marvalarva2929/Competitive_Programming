using namespace std;
#include <bits/stdc++.h>
#define nl '\n'
#define int long long

void solve() {
    int n; cin >> n;
    int a[n] = {};

    for (int i = 0; i < n; i++)
        cin >> a[i];
    
    int mn = 0, mx = (int)1e9;

    for (int i = 0; i < n - 1; i++) 
        if (a[i] > a[i + 1])
            mn = max(mn, (int)ceil((double)(a[i] + a[i + 1])/2));
        else if (a[i] < a[i + 1])
            mx = min(mx, (a[i] + a[i + 1])/2);

    if (mn > mx) {
        cout << -1 << nl;
        return;
    }
    cout << mn << nl;
    return; 
}   

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    int t; cin >> t;
    while (t--)
        solve();
}