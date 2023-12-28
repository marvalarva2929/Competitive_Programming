#include <bits/stdc++.h>
#define int long long
#define pi pair<int, int>
#define ff first
#define ss second
#define nl " \n"

using namespace std;
const int mxn = 1e3;
int a[mxn][mxn];
int ans[mxn];

void solve() {
    int n; cin >> n;
    fill(ans, ans + n, 0);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];

    for (int b = 0; b < 30; b++) 
        for (int i = 0; i < n; i++) {
            bool nd = 1;
            for (int j = 0; j < n; j++)
                if (i != j) {
                    nd &= (a[i][j] >> b) & 1;         
                }
            ans[i] += (nd << b);
        }
    
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (i != j && a[i][j] != (ans[i] | ans[j])) {
                cout << "NO" << nl;
                return; 
            }
    
    cout << "YES" << nl;
    for (int i = 0; i < n; i++)
        cout << ans[i] << nl[i == n -1];
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t; cin >> t;
    while (t--)
        solve();
}
