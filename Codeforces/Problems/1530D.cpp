using namespace std;
#include <bits/stdc++.h>
#define int long long
#define nl '\n'

void solve() {
    int n; cin >> n;
    int a[n + 1] = {};
    int res[n + 1] = {};
    int pos[n + 1] = {};
    bool used[n + 1] = {};
    for (int i = 1; i <= n; i++)    
        cin >> a[i];

    int ans = 0;
    for (int i = 1; i <= n; i++)
        if (!used[a[i]])
            res[i] = a[i],
            pos[a[i]] = i,
            used[a[i]] = true,
            ans++;

    int i = 1, j = 1;
    while (i < n && j < n) {
        while (i <= n && pos[i]) i++;
        while (j <= n && res[j]) j++;
        if (i > n || j > n) break;
        res[j] = i;
        pos[i] = j;
        if (j == i) {
            swap(res[pos[a[j]]], res[j]);
        }
    }
    int iter = 0;
    cout << ans << nl;
    for (int j : res)
        if (iter++)
            cout << j << " ";
    cout << nl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t; cin >> t;
    while (t--)
        solve();
}