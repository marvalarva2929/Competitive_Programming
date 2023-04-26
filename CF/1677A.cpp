using namespace std;
#include <bits/stdc++.h>
#define int long long
#define nl '\n'

void solve() {
    int n; cin >> n;
    int a[n] = {};
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int ans = 0;

    int g[n + 1] = {};
    for (int i = 0; i < n; i++)
        for (int j = i + 2; j < n; j++)
            if (a[i] > a[j])
                g[i]++;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i - 1; j++)
            if (a[j] > a[i])
                g[j]--;
        
        int curr[n + 1] = {};
        curr[0] = g[0];
        for (int j = 1; j <= i; j++)
            curr[j] = curr[j - 1] + g[j];
        
        for (int j = 0; j < i; j++)
            if (a[j] < a[i])
                ans += curr[i - 1] - curr[j]; 
    }

    cout << ans << nl;
    return;
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t; cin >> t;
    while (t--)
        solve();
}