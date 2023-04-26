using namespace std;
#include <bits/stdc++.h>
#define nl '\n'
#define int long long

void solve() {
    int n, k; cin >> n >> k;
    int h[n] = {}, p[n] = {};
    bool dead[n] = {};

    for (int i = 0; i < n; i++)
        cin >> h[i];
    for (int i = 0; i < n; i++)
        cin >> p[i];
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pi;

    for (int i = 0; i < n; i++)
        pi.push({p[i], i});

    int damage = 0;

    while (k >= 0 && pi.size()) {
        damage += k;
        while (pi.size() && h[pi.top().second] <= damage)
            pi.pop();
        int delta = pi.top().first;
        k -= delta;
    }

    cout << (pi.size() ? "NO" : "YES") << nl;
}   

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t; cin >> t;
    while (t--)
        solve();
}