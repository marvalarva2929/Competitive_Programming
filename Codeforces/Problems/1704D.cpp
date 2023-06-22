#include <bits/stdc++.h>
#define int long long
#define nl " \n"

using namespace std;

void solve() {
    int n, m; cin >> n >> m;

    vector<vector<int>> a(n, vector<int>(m, 0));
    
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> a[i][j];
    
    unordered_map<int, int> cnt;
    vector<int> prod(n);

    for (int i = 0; i < n; i++) {
        int prd = 0;
        for (int j = 0; j < m; j++)
            prd += (j + 1) * a[i][j];
        prod[i] = prd;
        cnt[prd]++;
    }
     
    for (int i = 0; i < n; i++)
        if (cnt[prod[i]] == 1) {
            int nor = i ? prod[i - 1] : prod[i + 1];

            cout << i + 1 << ' ' << prod[i] - nor << nl;
        }
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t; cin >> t;
    while (t--)
        solve();
}
