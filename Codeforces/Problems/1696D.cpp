#include <bits/stdc++.h>
#define int long long
#define nl " \n"

using namespace std;

const int mxn = 2.5e5;
int a[mxn], mn[2][mxn], mx[2][mxn], t[mxn+1];

void solve() {
    int n; cin >> n;
    for (int i = 0; i < 2; i++)
        fill(mn[i], mn[i] + n, INT_MAX),
        fill(mx[i], mx[i] + n, INT_MIN);
    
    for (int i = 0; i < n; i++)
        cin >> a[i],
        t[a[i]] = i;
 
    for (int i = 0; i < n; i++)
        if (i) 
            mx[0][i] = max(mx[0][i - 1], a[i]),
            mn[0][i] = min(mn[0][i - 1], a[i]);
        else
            mx[0][i] = a[i],
            mn[0][i] = a[i];

    for (int i = n - 1; i >= 0; i--)
        if (i < n - 1)
            mx[1][i] = max(mx[1][i + 1], a[i]),
            mn[1][i] = min(mn[1][i + 1], a[i]);
        else 
            mx[1][i] = a[i],
            mn[1][i] = a[i];

    int ans = 0;
    int idx = n;
    bool mode = 1;

    while (t[idx] != 0) {
        ans++;
        if (mode) idx = mn[0][t[idx]];
        else idx = mx[0][t[idx]];
        mode ^= 1;
    } 
    
    idx = n;
    mode = 1;
    

    while (t[idx] != n - 1) {
        ans++;
        if (mode) idx = mn[1][t[idx]];
        else idx = mx[1][t[idx]];
        mode ^= 1;
    }
    
    cout << ans << nl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t; cin >> t;
    while (t--)
        solve();
}
