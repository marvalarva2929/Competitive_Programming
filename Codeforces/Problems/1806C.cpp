using namespace std;
#include <bits/stdc++.h>    
#define int long long
#define nl '\n'

const int mxn = 2e5;
int a[2 * mxn];

void solve() {
    int n; cin >> n;
    int ans = 0, sum = 0;    

    for (int i = 0; i < n * 2; i++)
        cin >> a[i],
        sum += abs(a[i] + 1),
        ans += abs(a[i]);


    if (n == 1) {
        ans = (abs(a[0] - a[1]));
    }
    
    if (n == 2) {
        int x = 0;
        for (int i = 0; i < n * 2; i++)
            x += abs(a[i] - 2);
        ans = min(ans, x);
    }

    if (n % 2 == 0) {
        for (int i = 0; i < n * 2; i++)
            ans = min(ans, sum - abs(a[i] + 1) + abs(a[i] - n));
    }

    cout << ans << nl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t; cin >> t;
    while (t--)
        solve();
}