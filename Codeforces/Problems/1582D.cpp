using namespace std;
#include <bits/stdc++.h>
#define int long long
#define nl '\n'

void solve() {
    int n; cin >> n;
    int a[n] = {};
    int b[n] = {};
    for (int i = 0; i < n; i++)
        cin >> a[i];


    for (int i = 0; i < n - 1; i += 2)
        b[i] = -a[i + 1],
        b[i + 1] = a[i];

    
    if (n % 2) 
        if (b[n - 2] - a[n - 1] != 0)
            b[n - 1] = a[n - 2],
            b[n - 2] -= a[n - 1];
        else 
            b[n - 1] = -a[n - 2],
            b[n - 2] += a[n - 1]; 
    
    for (int i = 0; i < n; i++)
        cout << b[i] << " ";
    cout << nl;
    // cout << nl << check << nl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t; cin >> t;
    while (t--)
        solve();
}