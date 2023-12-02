#include <bits/stdc++.h>
#define int long long
#define pi pair<int, int>
#define ff first
#define ss second
#define nl " \n"

using namespace std;
const int mxn = 2e5;
int a[mxn];
int prf[mxn];

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int n; cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n);

    prf[0] = a[0];
    for (int i = 1; i < n; i++)
        prf[i] = prf[i - 1] + a[i];
    
    int s = 0;
    int ans = LLONG_MAX;

    for (int i = 0; i < n; i++) {
        int f = prf[n - 1] - prf[i];
        ans = min(ans, (a[i] * i) - s + f - (a[i] * (n - i - 1)));     
        s = prf[i];
    }
    
    cout << ans << nl;
}
