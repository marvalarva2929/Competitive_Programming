#include <bits/stdc++.h>
#define int long long
#define nl " \n"
#define pi pair<int, int>
#define ff first
#define ss second

using namespace std;
const int mxn = 1e5;
int a[mxn];
int n, k; 

bool check(int m) {
    int rn = 0;
    int mn = (m + 1) / 2;
    for (int i = n - 1; i > 1; i--)
        rn += a[i] < mn;

    for (int i = 0; i < n - 1; i++) {
        
        if (rn + (a[i] < m) + (a[i + 1] < m) <= k)
            return true;

        rn += a[i] < mn;
        if (i < n - 2) rn -= a[i + 2] < mn;
    }
    
    return false;
}

void solve() {
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int l = 0, r = 1e9 + 1;
    while (l < r - 1) {
        int m = (l + r) >> 1;
        //cout << l << " " << r << nl;
        if (check(m))
            l = m;
        else r = m;
    }
    
    cout << l << nl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t; cin >> t;
    while (t--)
        solve();
}
