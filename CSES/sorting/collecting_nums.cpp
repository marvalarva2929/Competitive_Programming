#include <bits/stdc++.h>
#define int long long
#define nl " \n"

using namespace std;
const int mxn = 2e5;
int a[mxn], wh[mxn];

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int n; cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i], wh[a[i] - 1] = i;
    
    int ans = 1;
    int lst = wh[0];
    for (int i = 1; i < n; i++)
        ans += wh[i] < lst,
            lst = wh[i];
    
    cout << ans << nl;
}
