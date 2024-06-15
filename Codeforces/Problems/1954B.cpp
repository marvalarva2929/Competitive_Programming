#include <bits/stdc++.h>
#define int long long
#define nl " \n"
#define pi pair<int, int>
#define ff first
#define ss second

using namespace std;
const int mxn = 3e5;
int a[mxn];

void solve() {
    int n; cin >> n;
    int mn = LLONG_MAX;
    int fs = 0;
    int cnt = 0;

    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        if (!i) fs = x;

        if (x == fs) cnt++;
        else mn = min(mn, cnt), cnt = 0;
    }
    mn = min(mn, cnt); 

    cout << (mn == n ? -1 : mn) << nl;
};

signed main() {
    cin.tie(0)->sync_with_stdio(false);
    
    int t; cin >> t;
    while (t--)
        solve();
}
