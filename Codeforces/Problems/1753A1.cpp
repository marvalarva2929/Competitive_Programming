using namespace std;
#include <bits/stdc++.h>
#define int long long
#define nl '\n'

void solve() {
    int n; cin >> n;
    int a[n] = {};
    int cnt[2]= {}; // -1: 0, 1: 1

    for (int i = 0; i < n; i++) {
        int c; cin >> c;
        a[i] = (c == 1 ? 1 : 0);
        cnt[a[i]]++;
    }
    


    if (cnt[0] == cnt[1])  {
        cout << n << nl;
        for (int i = 1; i <= n; i++)
            cout << i << " " << i << nl;
        return;
    } else {
        int g = (cnt[1] > cnt[0] ? 1 : 0), l = !g;


        int ind = cnt[l];
        int seql = cnt[g] - ind;
        if (seql&1) {
            cout << "-1" << nl;
            return;
        }
        bool covered[n] = {};

        vector<pair<int, int>> ans;
        int pneed = seql/2;

        for (int i = 0; i < n; i++)
            if (a[i] == l)
                ans.push_back({i, i}), covered[i] = true;

        for (int i = 0; i < n - 1; i++)
            if (a[i] == g && a[i + 1] == g && pneed)
                ans.push_back({i, i + 1}), pneed--, covered[i] = covered[i + 1] = true, i++;

        assert(pneed == 0);

        for (int i = 0; i < n; i++)
            if (!covered[i])
                ans.push_back({i, i});

        sort(ans.begin(), ans.end());


        cout << ans.size() << nl;
        for (auto p : ans)
            cout << p.first + 1 << " " << p.second + 1 << nl;
    }

}
signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    int t; cin >> t;
    while (t--)
        solve();
}