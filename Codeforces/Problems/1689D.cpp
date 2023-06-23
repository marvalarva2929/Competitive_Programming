#include <bits/stdc++.h>
#define int long long
#define nl " \n"
#define inf ((int)1e9)
#define pi pair<int, int>
#define ff first
#define ss second

using namespace std;

void solve() {
    int n, m; cin >> n >> m;
    vector<vector<bool>> a(n, vector<bool>(m));
    vector<int> first(m, INT_MAX), last(m, INT_MIN);
    vector<vector<int>> dp1(n, vector<int>(m));
    vector<vector<int>> dp2(n, vector<int>(m));
   
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            char c; cin >> c;
            a[i][j] = c == 'B'; 
            if (a[i][j])
                first[j] = min(first[j], i),
                last[j] = max(last[j], i);
        }
    
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            if (j == 0) { dp1[i][j] = -inf; continue; }
            
            dp1[i][j] = dp1[i][j - 1] + 1;
           
            if (first[j - 1] != INT_MAX)
                dp1[i][j] = max(dp1[i][j], max(abs(first[j - 1] - i), abs(last[j - 1] - i)) + 1);
        }
    
    for (int i = 0; i < n; i++)
        for (int j = m - 1; j >= 0; j--) {
            if (j == m - 1) { 
                if (first[j] != INT_MAX) dp2[i][j] = max(abs(i - first[j]), abs(i - last[j]));
                else dp2[i][j] = -inf;
                continue; 
            }

            dp2[i][j] = dp2[i][j + 1] + 1;
            
            if (first[j] != INT_MAX)
                dp2[i][j] = max(dp2[i][j], max(abs(first[j] - i), abs(last[j] - i)));
        }

    pair<int, pi> ans = {INT_MAX, {}};
    
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            ans = min(ans, {max(dp1[i][j], dp2[i][j]), {i, j}});
    
    cout << ans.ss.ff + 1 << " " << ans.ss.ss + 1 << nl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t; cin >> t;
    while (t--)
        solve();
}
