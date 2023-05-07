using namespace std;
#include <bits/stdc++.h>
#define int long long
#define nl '\n'

void solve() {
    int n; cin >> n;
    int a[n + 1] = {};
    bool f[n + 1][n + 1] = {};
    
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    
    int ans = 0;

    for (int i = 1; i <= n; i++) {
        if (i <= a[i]) 
            for (int j = i + 1; j <= n; j++) 
                if (a[j] <= a[i] && !f[j][i] && !f[i][j])
                    ans++, f[i][j] = f[j][i] = true;
        
        if (i >= a[i]) 
            for (int j = i - 1; j; j--)
                if (a[j] >= a[i] && !f[j][i] && !f[i][j])
                    ans++, f[i][j] = f[j][i] = true;
    }

    cout << ans << nl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t; cin >> t;
    while (t--)
        solve();
}