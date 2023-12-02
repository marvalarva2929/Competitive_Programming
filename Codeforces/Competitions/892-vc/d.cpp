#include <bits/stdc++.h>
#define int long long
#define pi pair<int, int>
#define ff first
#define ss second
#define nl " \n"

using namespace std;
const int mxn = 2e5;
pair<pi, pi> a[mxn];
int b[mxn], h[mxn], ans[mxn];

void solve() {
    int n; cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i].ff.ff >> a[i].ff.ss >> a[i].ss.ff >> a[i].ss.ss;
    sort(a, a + n);
    
    int m; cin >> m;
    for (int i = 0; i < m; i++)
        cin >> b[i], ans[i] = b[i];

    iota(h, h + m, 0);
    sort(h, h + m, [](const int & x, const int & y) -> bool {
                return b[x] < b[y];          
            });
    pi cmx = {a[0].ff.ff, a[0].ss.ss};

    int i = 0;
    int j = 0;

    while (i < n) {
        while (i < n && a[i].ff.ff <= cmx.ss) 
            cmx.ss = max(cmx.ss, a[i].ss.ss), 
            i++;
        //cout << i << " : " << cmx.ff << " " << cmx.ss << nl;
    
        for (; j < m; j++) {
            //cout << j << " : " << h[j] << nl;
            int x = b[h[j]];
            if (x <= cmx.ss && x >= cmx.ff) ans[h[j]] = cmx.ss;
            else if (x > cmx.ss) break;
        }
   
        cmx = {a[i].ff.ff, a[i].ss.ss};
   
        if (i == n) break;
    }
    
    for (int i = 0; i < m; i++)
        cout << ans[i] << nl[i == m -1];
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t; cin >> t;
    while (t--)
        solve();
}
