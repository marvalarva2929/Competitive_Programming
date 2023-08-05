#include <bits/stdc++.h>
#define int long long
#define nl " \n"
#define pi pair<int, int>
#define ff first
#define ss second

using namespace std;
const int mxn = 3e5, mxc = 1e6;
pi a[mxn];

void solve() {
    int n, c; cin >> n >> c;
    vector<int> best(c + 1, 0);
    
    for (int i = 0; i < n; i++) {
        int c, d, h; cin >> c >> d >> h;
        a[i] = {c, -(d * h)};
    }
    
    sort(a, a + n);
    for (int i = 0; i < n; i++)
        if (i == 0 || a[i].ff != a[i - 1].ff) {
            int dm = -a[i].ss;
            for (int j = 1; j * a[i].ff <= c; j++)
                best[j * a[i].ff] = max(best[j * a[i].ff], dm * j);
        }
    
    int mx = 0;
    for (int i = 0; i <= c; i++)
        best[i] = max(best[i], mx), 
        mx = max(mx, best[i]);

    int m;
    cin >> m;
    vector<int> mons;
    vector<int> t(m);
    iota(t.begin(), t.end(), 0);

    for (int i = 0; i < m; i++) {
        int d, h; cin >> d >> h;
        int dm = d * h;
        mons.push_back(dm);
    }
    
    sort(t.begin(), t.end(), [&mons](const int& a, const int& b) -> bool {
        return mons[a] < mons[b];
    });
    
    vector<int> ans(m, 0);

    int idx = 0;
    for (int j = 0; j < m; j++) {
        int i = t[j]; 
        while (idx < c && best[idx] <= mons[i]) idx++;
        if (best[idx] <= mons[i]) ans[i] = -1;
        else ans[i] = idx; 
    }
    
    for (int i = 0; i < m; i++)
        cout << ans[i] << nl[i == m - 1];

}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t = 1;;
    while (t--)
        solve();
}
