using namespace std;
#include <bits/stdc++.h>
#define int long long
#define nl '\n'
#define MAX (int)100 + 10
int a[MAX] = {};
int n;

bool can(int k) {
    int ca = 0;
    int ba = n - 1;
    bool vis[n] = {};
    int b[n] = {};
    for (int i = 0; i < n; i++)
        b[i] = a[i];

    while (k) {
        bool c = false;
        
        for (int i = 0; i < n; i++)
            if (b[i] <= k && !vis[i]) {
                c = true, vis[i] = true;
                break;
            }
        
        if (!c) {
            // cout << k << " : ";
            // for (int i = 0; i < n; i++)
            //     if (vis[i]) cout << -1 << " ";
            //     else cout << b[i] << " ";
            // cout << nl;
            return false;
        }
        b[ba--] += k;

        sort(a, a + n, greater<int>());
        k--;
    }
    return true;
}

void solve() {
    cin >> n;
    fill(a, a + n + 1, 0);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    sort(a, a + n, greater<int>());

    int l = 0, r = n + 1;
    while (l < r) {
        int m = (l + r)/2;   
        bool b = can(m);
        // cout << l << " " << r << " " << m << " " << b << nl;
        if (b)
            l = m + 1;
        else 
            r = m;
    }

    cout << --l << nl;
    return;
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t; cin >> t;
    while (t--)
        solve();
}