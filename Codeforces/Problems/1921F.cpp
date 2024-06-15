#include <bits/stdc++.h>
#define int long long
#define nl " \n"
#define pi pair<int, int>
#define ff first
#define ss second

using namespace std;
const int mxn = 1e5;
int a[mxn];
int pfi[322][mxn+322], pf[322][mxn+322];

void solve() {
    int pv = 0;
    int n, q; cin >> n >> q;

    for (int i = 0; i < n; i++)
        cin >> a[i];

    while (pv*pv < n) pv++;
    
    for (int i = 0; i < pv; i++) {
        for (int j = 0; j <= i; j++)
            pfi[i][j] = pf[i][j] = 0;

        for (int j = 0; j < n; j++) {
            pfi[i][i + j + 1] = pfi[i][j] + (a[j] * (j / (i + 1) + 1));
            pf[i][i + j + 1] = pf[i][j] + a[j];
        }
    }
    
    //while (true) {
    //    int x, y; cin >> x >> y;
    //    cout << pfi[x][y] << " : " << pf[x][y] << nl;
    //}

    while (q--) {
        int s, d, k; cin >> s >> d >> k;
        s--;

        if (d >= pv) {
            int ans = 0;
            for (int i = 1; i <= k; i++)
                ans += a[s + ((i - 1) * d)] * i;
            cout << ans << " "; 
        } else {
            int ls = s + (k * d) - d, st = s;
            //cout << q << " : " << pf[d - 1][ls + d] << nl;
            cout << (pfi[d - 1][ls + d] - pfi[d - 1][st]) - ((pf[d - 1][ls + d] - pf[d - 1][st]) * (st / (d))) << " ";
        }
    }
    cout << nl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t; cin >> t;
    while (t--)
        solve();
}
