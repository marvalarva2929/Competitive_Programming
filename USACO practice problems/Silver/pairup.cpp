using namespace std;
#include <bits/stdc++.h>
#define int long long
#define nl '\n'
#define pi pair<int, int>

const int mxn = (int)1e5 + 10;
pi a[mxn];

signed main() {
    ifstream cin("pairup.in");
    ofstream cout("pairup.out");
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        int x, y; cin >> x >> y;
        a[i] = {y, x};
    }
    sort(a, a + n);
    int l = 0, r = n - 1;
    int ans = 0;

    while (l <= r) {
        ans = max(ans, a[l].first + a[r].first); 
        int mn;
        if (l == r) {
            mn = a[l].second/2;
        } else {
            mn = min(a[l].second, a[r].second);
        }
        a[l].second -= mn;
        a[r].second -= mn;
        if (a[l].second == 0) l++;
        if (a[r].second == 0) r--;
    }
    cout << ans << nl;
}