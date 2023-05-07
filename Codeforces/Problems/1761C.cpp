using namespace std;
#include <bits/stdc++.h>
#include <set>
#define int long long
#define nl '\n'

void solve() {
    int n; cin >> n;
    set<int> ans[n] = {};
    for (int i = 1; i <= n; i++)
        ans[i - 1].insert(i);
    


    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            char c; cin >> c;
                if (c&1) 
                    ans[j].insert(ans[i].begin(), ans[i].end());
        }
    
    for (int i = 0; i < n; i++) {
        cout << ans[i].size() << " ";
        for (int a : ans[i])
            cout << a << " ";
        cout << nl;
    }
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    int t; cin >> t;
    while (t--)
        solve();
}