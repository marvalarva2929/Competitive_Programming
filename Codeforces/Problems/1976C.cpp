#include <bits/stdc++.h>
#define int long long
#define nl " \n"
#define pi pair<int, int>
#define ff first
#define ss second

using namespace std;
const int mxn = 2e5;
int a[mxn][2], c[mxn], ans[mxn];

void solve() {
    int n, m; cin >> n >> m;
    for (int i = 0; i < n + m + 1; i++)
        cin >> a[i][0];
    for (int i = 0; i < n + m + 1; i++)
        cin >> a[i][1];
       
    int score = 0;
    int cn = 0, cm = 0;
    int f[] = {-1, -1};

    for (int i = 0; i < n + m; i++) {
        if (a[i][0] > a[i][1]) {
            if (cn < n) score += a[i][0], cn++, c[i] = 0;
            else score += a[i][1], cm++, c[i] = 1;
            
            if (c[i] == 1 && f[0] == -1) f[0] = i;
        } else {
            if (cm < m) score += a[i][1], cm++, c[i] = 1;
            else score += a[i][0], cn++, c[i] = 0;
            
            if (c[i] == 0 && f[1] == -1) f[1] = i;
        }
    }
    ans[n + m] = score;

    for (int i = 0; i < n + m; i++) {
        for (int j = 0; j < 2; j++) {
            if (a[i][j] > a[i][!j]) {
                ans[i] = score - a[i][c[i]]; 
                if (c[i] == j) {
                    if (f[j] != -1) ans[i] += a[f[j]][j] - a[f[j]][!j] + a[n + m][!j];
                    else ans[i] += a[n + m][j];
                } else {
                    ans[i] += a[n + m][!j]; 
                }
            }
        }
    }

    for (int i = 0; i < n + m + 1; i++)
        cout << ans[i] << nl[i == n + m];

}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t; cin >> t;
    while (t--)
        solve();
}
