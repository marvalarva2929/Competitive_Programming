#include <bits/stdc++.h>
#define int long long

using namespace std;
const int mxn = 2e5;
int a[mxn];

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int n; cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    
    int mx = 0;
    int ans = 0;

    for (int i = 0; i < n; i++) {
        mx = max(mx, a[i]);
        ans += mx - a[i];
    }
    
    cout << ans << endl;
}
