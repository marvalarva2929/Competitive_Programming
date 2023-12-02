#include <bits/stdc++.h>
#define int long long
#define nl " \n"
#define pi pair<int, int>
#define ff first
#define ss second

using namespace std;

void solve() {
    int n; cin >> n;
    vector<vector<int>> a(n, vector<int>());
    int mn = LLONG_MAX;
    vector<int> smn;

    for (int i = 0; i < n; i++) {
        int m; cin >> m;
        a[i] = vector<int>(m);
        pi mns = {LLONG_MAX, LLONG_MAX};

        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            if (a[i][j] <= mns.ff)
                mns.ss = mns.ff,
                mns.ff = a[i][j];
            else if (a[i][j] < mns.ss)
                mns.ss = a[i][j];
        }
        mn = min(mns.ff, mn);
        smn.push_back(mns.ss);
    }
   
    sort(smn.begin(), smn.end());
    
    int ans = mn;
    for (int i = 1; i < smn.size(); i++)
        ans += smn[i];

    cout << ans << nl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t; cin >> t;
    while (t--)
        solve();
}
