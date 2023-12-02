#include <bits/stdc++.h>
#define int long long
#define nl " \n"
#define pi pair<int, int>
#define ff first
#define ss second

using namespace std;
const int mxn = 1e5;
int a[mxn];

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int n, aa, b; cin >> n >> aa >> b;
    int ans = b * n;

    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n);
    

    ans += (aa * abs(a[n - 1] - a[0]));
    
    ans += aa * (min(abs(0 - a[0]), abs(0 - a[n - 1])));
    
    cout << ans << nl;
}
