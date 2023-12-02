#include <bits/stdc++.h>
#define int long long
#define pi pair<int, int>
#define ff first
#define ss second
#define nl " \n"

using namespace std;
const int mxn = 1e5;
int a[mxn], b[2 * mxn];

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int n; cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    
    bitset<2 * mxn> p = 1;
    int x = 0;

    for (int i = 0; i < n; i++) {
        p |= ((p >> i) << (i + a[i])); 
    }
    
    int ans = 0;
    int mn = INT_MAX;
    for (int i = 2 * (mxn) - 1; i >= 0; i--) {
        if (p[i]) mn = i;
        b[i] = mn; 
    }
    
    int s = 0;
    for (int i = 0; i < n; i++) {
        s += a[i];
        if (b[i] != INT_MAX)
            ans = max(ans, s - b[i]);
    }
    
    cout << ans << nl;
}
