#include <bits/stdc++.h>
#define int long long
#define nl " \n"
#define pi pair<int, int>
#define ff first
#define ss second

using namespace std;
const int mxn = 1e5;
int a[mxn];

void solve() {
    int n; cin >> n;
    int mx = 0;
    for (int i = 0; i < n; i++)
        cin >> a[i];
   
    if (n == 2) {
        cout << min(a[0], a[1]) << nl;
        return;
    }

    vector<int> c = {0, 1, 2};

    for (int i = 1; i < n - 1; i++) {
        vector<int> b = {a[i - 1], a[i], a[i + 1]};
        sort(b.begin(), b.end());
        mx = max(mx, b[1]);
    }
    
    cout << mx << nl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t; cin >> t;
    while(t--)
        solve();
}
