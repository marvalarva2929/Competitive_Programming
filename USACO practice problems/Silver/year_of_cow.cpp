#include <bits/stdc++.h>
#define int long long
#define nl " \n"
#define pi pair<int, int>
#define ff first
#define ss second

using namespace std;
const int mxn = 0x10000;
pi a[mxn];

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int n, k; cin >> n >> k; --k;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        a[i] = {x / 12, x / 12 + 1};
    }
    
    sort(a, a + n);
    vector<pi> all;
    all.push_back(a[0]);
    for (int i = 1; i < n; i++)
        if (a[i].ff > all.back().ss) all.push_back(a[i]);
        else all.back().ss = a[i].ss;
    
    vector<int> tk;
    int cur = 0;
    for (pi p : all)
        tk.push_back(p.ff - cur), cur = p.ss;
    sort(tk.begin(), tk.end(), greater<int>());
    
    int ans = all.back().ss;
    for (int i = 0; i < min(k, (int)tk.size()); i++)
        ans -= tk[i];

    cout << ans * 12 << endl;
}
