#include <bits/stdc++.h>
#define int long long
#define nl " \n"
#define ff first
#define ss second

using namespace std;
const int mxn = 2e5;
int a[mxn], cnt[mxn+1];

void solve() {
    int n; cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    
    cnt[n - 1] = cnt[n] = 0;
    for (int i = n - 2; i >= 0; i--)
        cnt[i] = cnt[i + 1] + (a[i] >= a[i + 1]);
    
    int ans = cnt[0];
    int c2 = 0;
    for (int i = 0; i < n; i++) {
        if (i) c2 += a[i] >= a[i - 1];
        ans = min(ans, 1 + c2 + cnt[i + 1]); 
    }
    
    cout << ans << nl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t; cin >> t;
    while (t--)
        solve();
}
