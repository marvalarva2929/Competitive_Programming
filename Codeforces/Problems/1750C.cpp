using namespace std;
#include <bits/stdc++.h>
#define int long long
#define yes "yes"
#define no "no"
#define nl '\n'

void solve() {
    int n; cin >> n;
    vector<bool> a, b;
    string aa, bb; cin >> aa >> bb;

    for (char c : aa) 
        a.push_back(c&1);

    for (char c : bb) 
        b.push_back(c&1);

    bool flag = false;
    
    for (int i = 0; i < n; i++)
        if (a[i] == b[i]) {
            flag = true; break;
        }

    if (flag && aa != bb) {
        cout << no << nl;
        return;
    }

    vector<pair<int, int>> ans;
    int cnt = 0;
    for (int i = 0; i < n; i++)
        if (!a[i])
            ans.push_back({i + 1, i + 1}), cnt++;

    if (aa != bb) cnt--;
    if (cnt % 2)
        ans.push_back({1, n});
    else
        ans.push_back({1, 1}), ans.push_back({2, n});
    cout << yes << nl << ans.size() << nl;


    for (auto p : ans)
        cout << p.first << " " << p.second << nl;
    // cout << nl;
}       

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t; cin >> t;
    while (t--)
        solve();
}