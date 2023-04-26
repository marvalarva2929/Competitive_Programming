using namespace std;
#include <bits/stdc++.h>
#define int long long
#define nl '\n'
#define pi pair<int, int>
#define vpi vector<pi>

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int n, m; cin >> n >> m;
    vector<pair<pi, int>> sec;
    vector<pair<pi, pi>> serc_stalls;
    for (int i = 0; i < n; i++) {
        int s, e, c; cin >> s >> e >> c;
        sec.push_back({{s, e}, c});
    }

    for (int i = 0; i < m; i++) {
        int s, e, c, r; cin >> s >> e >> r >> c;
        serc_stalls.push_back({{s, e}, {r, c}});
    }

    int mx = (1 << (m + 1));
    bitset<2048> stalls;
    int ans = INT_MAX;

    for (int i = 0; i < mx; i++) {
        stalls = i;

        vector<pair<pi, pi>> curr_serc;
        int coverage[101] = {};
        int cost = 0;

        for (int j = 0; j < m; j++)
            if (stalls[j]) {
                for (int k = serc_stalls[j].first.first; k <= serc_stalls[j].first.second; k++)
                    coverage[k] += serc_stalls[j].second.first;
                cost += serc_stalls[j].second.second;
            }

        bool works = true;

        for (auto cow : sec) {
            int start = cow.first.first;
            int end = cow.first.second;
            int need = cow.second;

            for (int i = start; i <= end; i++)
                if (coverage[i] < need)
                    { works = false; break; }

            if (!works) break;
        }

        if (works) ans = min(ans, cost);
    }

    cout << ans << nl;
}