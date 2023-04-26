using namespace std;
#include <bits/stdc++.h>
#define int long long
#define nl '\n'
#define MAX (int)100
vector<int> atx, aty;
vector<pair<int, int>> cows;

signed main() {
    ifstream cin("balancing.in");
    ofstream cout("balancing.out");

    int n, b; cin >> n >> b;
    for (int i = 0; i < n; i++) {
        int x, y; cin >> x >> y;
        cows.push_back({x, y});
    }

    int ans = LLONG_MAX;

    for (int i = 0; i < n; i++) {
        auto cowx = cows[i];
        for (int j = 0; j < n; j++) {
            auto cowy = cows[j];
            int ul = 0, ll = 0, ur = 0, lr = 0;

            for (auto cow : cows) {
                if (cow.first <= cowx.first) {
                    if (cow.second >= cowy.second)
                        ul++;
                    else ll++;
                } else {
                    if (cow.second >= cowy.second)
                        ur++;
                    else lr++;
                }
            }
            ans = min(ans, max(max(ul, ll), max(ur, lr)));
        }
    }
    cout << ans << nl;
}