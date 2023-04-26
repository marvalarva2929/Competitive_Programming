using namespace std;
#include <bits/stdc++.h>
#define int long long
#define nl '\n'
#define MAX (int)1e5 + 10
#define pi pair<long long, long long>
#define vpi vector<pi>
#define vi vector<long long>
vi wcx[MAX], wcy[MAX];

void solve() {
    int n, m; cin >> n >> m;
    set<int> allColors; 


    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            int x; cin >> x;
            wcx[x].push_back(i);
            wcy[x].push_back(j);
            allColors.insert(x);
        }

    int ans = 0;


    for (int color : allColors) {
        vi c = wcx[color];
        vi d = wcy[color];
        sort(c.begin(), c.end());
        sort(d.begin(), d.end());

        int k = d.size();
        int x = 0, y = 0;
        for (int i = 0; i < k; i++)
            x += c[i] * ((2 * i) - k + 1); 
        for (int i = 0; i < k; i++)
            y += d[i] * ((2 * i) - k + 1); 
        
        ans += x + y;
    }

    cout << ans << nl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t = 1;
    while (t--)
        solve();
}