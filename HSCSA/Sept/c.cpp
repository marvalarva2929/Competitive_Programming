#include <bits/stdc++.h>
#define int long long
#define nl " \n"
#define pi pair<int, int>
#define ff first
#define ss second

using namespace std;
const int mxn = 1e5;
int a[mxn+1];

signed main() {

    int k; cin >> k;
    int n; cin >> n;
    int mx = 0;
    
    for (int i = 0; i < n; i++)
        cin >> a[i], mx = max(mx, a[i]);
    sort(a, a + n, greater<int>());
    a[n] = 0;
    
    if (k > mx) cout << 0 << nl;
    else {
        int diff = mx - (mx - k) / 2 - 1;
        int t = 0;

        for (int i = 0; i < n; i++)
            t += max((int)0, a[i] - diff);
        cout << t << nl;
    }
}
