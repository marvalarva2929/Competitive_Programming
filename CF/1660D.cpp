using namespace std;
#include <bits/stdc++.h>
#define int long long
#define nl '\n'

void solve() {
    int n; cin >> n;
    int a[n + 1] = {};
    int ni[n + 1] = {};
    int w[n + 1] = {};

    pair<int, int> ans = {0, 0};
    int mx = 0;
    vector<int> ind;
    ind.push_back(0);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (!a[i])
            ind.push_back(i);
    }
    ind.push_back(n + 1);
    sort(ind.begin(), ind.end());

    for (int i = 1; i <= n; i++) {
        if (a[i] < 0)
            ni[i]++;
        if (abs(a[i]) == 2)
            w[i]++;
        w[i] += w[i - 1];
        ni[i] += ni[i - 1];
    }

    for (int i = 0; i < ind.size() - 1; i++) {
        int i_one = ind[i], i_two = ind[i + 1];
        int nugs = ni[i_two - 1] - ni[i_one]; 
        int twos = w[i_two - 1] - w[i_one];

        // cout << i_one << " " << i_two << " " << nugs << " " << twos << " " << nugs << nl;

        if (nugs % 2) {
            int j = i_one + 1;
            int t_twos = twos;
            
            for (j; j < i_two; j++) {
                if (abs(a[j]) == 2)
                    t_twos--;
                if (a[j] < 0)
                    break;
            }
            
            // cout << "FL" << " " << j << " : " << t_twos << nl;

            if (t_twos >= mx)
                ans = {j, (n - i_two + 1)}, mx = t_twos;
            
            j = i_two - 1;
            t_twos = twos;

            for (j; j > i_one; j--) {
                if (abs(a[j]) == 2)
                    t_twos--;
                if (a[j] < 0)
                    break;
            }

            // cout << "FR" << " " << j << " : " << t_twos << nl;

            if (t_twos > mx)
                ans = {i_one, (n - j + 1)}, mx = t_twos;

        } else {
            if (twos >= mx) 
                mx = twos, ans = {i_one, n - i_two + 1};
        }
    }

    cout << ans.first << " " << ans.second << nl;

}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t; cin >> t;
    while (t--)
        solve();
}