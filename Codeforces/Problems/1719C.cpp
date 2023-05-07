using namespace std;
#include <bits/stdc++.h>
#define int long long
#define nl '\n'

void solve() {
    int n, e; cin >> n >> e;
    pair<int, int> a[n] = {};
    int ans[n + 1] = {};
    int mxt[n] = {};
    vector<int> wins[n + 1] = {};

    deque<pair<int, int>> q;

    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        a[i] = {x, i};
        q.push_back(a[i]);
    }


    int round = 0;

    while (true) {
        auto one = q.front(); q.pop_front();
        auto two = q.front(); q.pop_front();
        if (one.first == n || two.first == n) break;
                
        if (one.first > two.first) 
            ans[one.first]++, q.push_front(one), q.push_back(two), wins[one.first].push_back(round);
        else 
            ans[two.first]++, q.push_front(two), q.push_back(one), wins[two.first].push_back(round);

        ans[n]--;
        round++;
    }



    for (int i = 0; i < e; i++) {
        int x, k; cin >> x >> k;
        x--;
        if (a[x].first == n) 
            cout << max((int)0, (int)ans[a[x].first] + k) << nl;
        else 
            cout << (lower_bound(wins[a[x].first].begin(), wins[a[x].first].end(), k) - wins[a[x].first].begin()) << nl;
    }

}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t; cin >> t;
    while (t--)
        solve();
}