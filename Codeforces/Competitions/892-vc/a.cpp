#include <bits/stdc++.h>
#define int long long
#define pi pair<int, int>
#define ff first
#define ss second
#define nl " \n"

using namespace std;
const int mxn = 100;
int a[mxn];

void solve() {
    int mx = 0;
    int n; cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i], mx = max(mx, a[i]);

    vector<int> b, c;
    for (int i = 0; i < n; i++)
        if (a[i] == mx) c.push_back(mx);
        else b.push_back(a[i]);
    
    if (!b.size()) cout << -1 << nl;
    else {
        cout << b.size() << " " << c.size() << nl;
        for (int x : b)
            cout << x << " ";
        cout << nl;

        for (int x : c)
            cout << x << " ";
        cout << nl;
    }
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);
    
    int t; cin >> t;
    while (t--)
        solve();
}
