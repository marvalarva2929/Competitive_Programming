using namespace std;
#include <bits/stdc++.h>
#define int long long
#define nl '\n'

void solve() {
    int n, q; cin >> n >> q;
    int a[n] = {};
    bool ans[n] = {};
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int cur = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (a[i] <= cur)
            ans[i] = true;
        else if (a[i] > cur && cur < q)
            ans[i] = true, cur++;
    }   

    for (int i : ans)
        cout << i;
    cout << nl;
    
    

}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t; cin >> t;
    while (t--)
        solve();
}