#include <bits/stdc++.h>
#define int long long
#define pi pair<int, int>
#define ff first
#define ss second
#define nl " \n"

using namespace std;
const int mxn = 2e5;
int a[mxn];
int prf[mxn + 1];

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int n; cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    prf[1] = a[0];
    for (int i = 2; i <= n; i++)
        prf[i] = prf[i - 1] + a[i - 1];
    
    int ans = LLONG_MIN;
    int mn = 0;

    for (int i = 1; i <= n; i++)
        ans = max(ans, prf[i] - mn), mn = min(mn, prf[i]);
    cout << ans << nl;
}
