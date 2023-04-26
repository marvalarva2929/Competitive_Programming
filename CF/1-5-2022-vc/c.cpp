using namespace std;
#include <bits/stdc++.h>
#define int long long
#define nl '\n'

void solve() {
    int n; cin >> n;
    set<int> o, t;
    int ans[n][2] = {};
    int assign[n] = {};

    pair<int, int> a[n] = {};
    for (int i = 0; i < n; i++) { int x; cin >> x; a[i] = {x, i}; }

    sort(a, a + n);

    for (int i = 1; i <= n; i++)
        o.insert(i), t.insert(i);

    for (int i = 0; i < n; i++) {
        int oa = o.count(a[i].first), ta = t.count(a[i].first);
        if (oa) 
            o.erase(a[i].first), ans[i][0] = a[i].first, assign[a[i].second] = i;
        else if (ta) 
            t.erase(a[i].first), ans[i][1] = a[i].first, assign[a[i].second] = i;
        else {
            cout << "NO" << nl;
            return;
        }
    }

    int i = 0;
    for (int x : o) {
        while (ans[i][0]) i++;
        ans[i][0] = x;
    }
    
    i = 0;
    for (int x : t) {
        while (ans[i][1]) i++;
        ans[i][1] = x;
    }


    for (int i = 0; i < n; i++)
        if (a[i].first != max(ans[i][1], ans[i][0])) {
            cout << "NO" << nl;
            return; 
        }

    cout << "YES" << nl;
    
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < n; j++) 
            cout << ans[assign[j]][i] << " ";
        cout << nl;
    }
}


signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t; cin >> t;
    while (t--)
        solve();
}