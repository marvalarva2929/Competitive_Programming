#include <bits/stdc++.h>
#define int long long
#define nl " \n"
#define pi pair<int, int>
#define ff first
#define ss second

using namespace std;
    
const int mxn = 3e5;

void solve() {
    int n; cin >> n;
    
    int sum = 0, mx = 0;
    pi ans = {0, 0};

    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        sum += x;
        mx = max(mx, sum); 
        ans = min(ans, {sum - mx, mx});
    }
    
    cout << ans.ss << nl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t; cin >> t;
    while (t--)
        solve();
}
