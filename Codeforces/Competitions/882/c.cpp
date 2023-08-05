#include <bits/stdc++.h>
#define int long long
#define nl " \n"
#define pi pair<int, int>
#define ff first
#define ss second

using namespace std;
const int mxn = 1e5;
int a[mxn];
int prf[mxn];

void solve() {
    int n; cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    
    prf[0] = a[0];
    for (int i = 1; i < n; i++)
        prf[i] = prf[i - 1] ^ a[i];

    unordered_map<int, bool> is;
    is[0] = 1;

    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < (1 << 8); j++)
            if (is[prf[i] ^ j])
                ans = max(ans, j);
        is[prf[i]] = 1; 
    }
    
    cout << ans << nl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t; cin >> t;
    while (t--)
        solve();
}
