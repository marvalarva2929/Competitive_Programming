#include <bits/stdc++.h>
#define int long long
#define nl " \n"
#define pi pair<int, int>
#define ff first
#define ss second

using namespace std;
const int mxn = 1e5;
pi a[mxn];
int ans[mxn];

void solve() {
    int n; cin >> n;
    multiset<pi> all;

    for (int i = 0; i < n; i++) {
        cin >> a[i].ff, a[i].ss = i;
        all.insert(a[i]);
    }
    
    int cur = 0;
    for (int i = n; i; i--) {
        auto b = all.begin(),
             e = --all.end();

        if ((*b).ff == cur) ans[(*b).ss] = -i, all.erase(b);
        else if ((*e).ff - cur == i) cur++, ans[(*e).ss] = i, all.erase(e);
        else {
             
            cout << "NO" << nl;
            return;
        }
    }
    
    cout << "YES" << nl;
    for (int i = 0; i < n; i++)
        cout << ans[i] << nl[i == n -1];
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t; cin >> t;
    while (t--)
        solve();
}
