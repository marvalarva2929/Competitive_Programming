#include <bits/stdc++.h>
#define int long long
#define nl '\n'
#define pi pair<int, int>
#define ff first
#define ss second

using namespace std;

void solve() {
    int m, n; cin >> m >> n;
    vector<vector<int>> a(m, vector<int>(n));
    vector<int> mx(n);
    vector<pi> storemx(m, {INT_MIN, INT_MIN});
    int allMin = INT_MAX;

    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
            if (a[i][j] > a[mx[j]][j])
                mx[j] = i;
        }
    
    for (int i = 0; i < n; i++)
        allMin = min(allMin, a[mx[i]][i]);
    
    for (int j = 0; j < m; j++)
        for (int i = 0; i < n; i++)
            if (storemx[j].ff < a[j][i])
                storemx[j].ss = storemx[j].ff,
                storemx[j].ff = a[j][i];
            else if (storemx[j].ss < a[j][i])
                storemx[j].ss = a[j][i];
    
    set<int> allStores;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (a[j][i] == a[mx[i]][i]) {
                allStores.insert(j);
                break;
            }
   
    if (allStores.size() == n) {

        pair<pi, int> minSwap = {{0 , 0}, 0};
        int ans = INT_MIN;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                int g = storemx[j].ff, l = storemx[j].ss;
                int thisGuy = a[j][i];
                int theOtherGUy = (thisGuy == g ? l : g); 
                
                //cout << i << " " << j << " : " << thisGuy << " " << theOtherGUy << nl;

                ans = max(ans, min(allMin, min(thisGuy, theOtherGUy)));
           }
        }

        cout << ans << nl;
    } else {
        cout << allMin << nl;
    }
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t; cin >> t;
    while (t--)
        solve();
}
