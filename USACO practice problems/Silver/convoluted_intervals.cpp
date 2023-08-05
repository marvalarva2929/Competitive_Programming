#include <bits/stdc++.h>
#define int long long
#define nl endl
#define pi pair<int, int>
#define ff first
#define ss second

using namespace std;
const int mxn = 2e5, mxm = 5e3;
pi a[mxn];
int start[mxm + mxm + 1], bac[mxm + mxm + 1];

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int n, m; cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> a[i].ff >> a[i].ss;

    vector<int> fr(m + m + 1);
    for (int i = 0; i < n; i++)
        fr[a[i].ff]++;
    
    for (int i = 0; i <= m; i++)
        for (int j = 0; j <= m; j++)
            start[i + j] += fr[i] * fr[j];

    fill(fr.begin(), fr.end(), 0);
    for (int i = 0; i < n; i++)
        fr[a[i].ss]++;

    for (int i = 0; i <= m; i++)
        for (int j = 0; j <= m; j++)
            bac[i + j] += fr[i] * fr[j];
    
    int cur = 0;
    for (int i = 0; i <= m + m; i++) {
        cur += start[i];
        cout << cur << nl;
        cur -= bac[i];
    }

}
