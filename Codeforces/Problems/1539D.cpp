using namespace std;
#include <bits/stdc++.h>
#define int long long
#define nl '\n'
#define pi pair<long long, long long>
#define print(x) for (auto i : x) { cout << i.first << " " << i.second << nl; }
bool compear(pi & a, pi & b) {
    if (a.second == b.second)
        return a.first < b.first;
    return a.second < b.second;
}

void solve() {
    int n; cin >> n;
    int ans = 0;
    vector<pi> all;
    for (int i = 0; i < n; i++) {
        int x, y; cin >> x >> y;
        all.push_back({x, y});
    }
    sort(all.begin(), all.end(), compear);

    int bought = 0;
    int items = 0;
    int i = 0;
    while (i < all.size()) {
        while (i < all.size() && all[i].second <= bought) {
            ans += all[i].first;
            bought += all[i].first;
            items++;
            i++;
        }
        
        // cout << i << " : " << bought << nl; print(all);
        // cout << nl;

        if (all.size() == 0 || i >= all.size()) break;

        while (i < all.size() && bought < all[i].second) {
            int new_bought = min(all[i].second - bought, all.back().first);
            // cout << new_bought << nl;
            bought += new_bought;
            ans += 2 * new_bought;
            all.back().first -= new_bought;
            if (all.back().first == 0)
                all.pop_back(),
                items++;
        }
        // cout << i << " : " << bought << nl; print(all);
        // cout << nl;
    }
    cout << ans << nl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t = 1;
    while (t--)
        solve();
}