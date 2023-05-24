#include <bits/stdc++.h>
#define int long long
#define nl '\n'
#define pi pair<int, int>
#define ff first
#define ss second

using namespace std;

const int mxn = 2e5;
int a[mxn];
int pref[mxn];
int tpref[4 * mxn];

void build(int v, int l, int r) {
    if (l == r) {
        tpref[v] = pref[l];
        return;
    }
    
    int m = (l + r) >> 1;

    build(v * 2, l, m);
    build(v * 2 + 1, m + 1, r);
    tpref[v] = min(tpref[v * 2], tpref[v * 2 + 1]);
}

int getMin(int v, int tl, int tr, int l, int r) {
    if (l > r)
        return INT_MAX;
    if (l == tl && r == tr) 
        return tpref[v];

    int tm = (tl + tr) >> 1;
    return min(
            getMin(v * 2, tl, tm, l, min(r, tm)),
            getMin(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r));
}

void solve() {
    int n, s; cin >> n >> s;
    fill(a, a + n, 0);
    fill(tpref, tpref + (n * 4), INT_MAX);
    fill(pref, pref + n, 0);

    for (int i = 0; i < n; i++)
        cin >> a[i];
        
    pref[0] = a[0];
    for (int i = 1; i < n; i++)
        pref[i] += a[i] + pref[i - 1];
    build(1, 0, n - 1);

   // for (int i = 0; i < n; i++)
   //     cout << pref[i] << " ";
   // cout << nl;
    
  //  while (true) {
  //      int x, y; cin >> x >> y;
  //      cout << getMin(1, 0, n - 1, x, y) << nl;
  //  }

    int l = 0, r = 0;
    int cur = INT_MAX;
    int sum = 0; 
    
    pair<int, pi> ans = {0, {0, 0}};

    while (r < n) {
        while (r < n && min(cur, sum + a[r]) + s >= 0)
           sum += a[r],
           cur = min(cur, sum),
           r++;
        
        ans = max(ans, {r - l, {l, r}});
        if (r == n) break;
        sum -= a[l];
        l++;
        cur = getMin(1, 0, n - 1, l, r - 1) - pref[l - 1];
    }  

    if (ans.ff == 0) cout << -1 << nl;
    else cout << ans.ss.ff + 1 << " " << ans.ss.ss << nl;
}

signed main() {
  cin.tie(0)->sync_with_stdio(false);

    int t; cin >> t;
    while (t--)
        solve();
}
