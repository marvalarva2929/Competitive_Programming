#include <bits/stdc++.h>
#define int long long
#define nl " \n"
#define pi pair<int, int>
#define ff first
#define ss second

using namespace std;

void solve() {
    int n, x; cin >> n >> x;
    vector<int> a;
    a.push_back(0);

    for (int i = 0; i < n; i++) {
        int y; cin >> y;
        a.push_back(y);
    }
    
    for (int i = n; i > 0; i--)
        a.push_back(x + (x - a[i]));

    int mx = 0;
    for (int i = 1; i < a.size(); i++) {
        mx = max(mx, a[i] - a[i - 1]);
    }
    
    cout << mx  << nl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t; cin >> t;
    while (t--)
        solve();
}
