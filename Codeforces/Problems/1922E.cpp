#include <bits/stdc++.h>
#define int long long
#define nl " \n"
#define pi pair<int, int>
#define ff first
#define ss second

using namespace std;

void solve() {
    int n; cin >> n;
    int mn = 0, mx = 0;
    
    vector<int> ans;
    int b = 0;
    int m = n;
    while (m != 1) m >>= 1, b++;
    for (int i = b - 1; i >= 0; i--) {
        ans.push_back(mx++);
        if ((n >> i) & 1)
            ans.push_back(--mn);
    }
    cout << ans.size() << nl;
    for (int z : ans)
        cout << z << " ";
    cout << nl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t; cin >> t;
    while (t--)
        solve();
}
