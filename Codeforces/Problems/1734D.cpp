using namespace std;
#include <bits/stdc++.h>
#define int long long
#define nl '\n'
#define no "no"
#define yes "yes"
#define print(x, y, z) for (int i = y; i <= z; i++) {cout << x[i] << " ";} cout << nl;
#define pi pair<int, int>
const int mxn = (int)2e5 + 20;


void solve() {
    int n, k; cin >> n >> k;
    k--;
    int a[n] = {};
    int ps[n + 1] = {};
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        ps[i] = ps[i - 1] + a[i - 1];
    
    vector<pi> lg, rg;
    int l = k, r = k + 1;
    for (int i = k - 1; i >= 0; i--)
        if (ps[i] <= ps[l] || i == 0) {
            int sum = 0;
            int mn = 0;
            for (int j = l - 1; j >= i; j--) {
                sum += a[j];
                mn = min(mn, sum);
            }
            lg.push_back({sum, -mn});
            l = i;
        }

    for (int i = k + 2; i <= n; i++) {
        if (ps[i] >= ps[r] || i == n) {
            int sum = 0;
            int mn = 0;
            for (int j = r; j < i; j++) {
                sum += a[j];
                mn = min(mn, sum);
            }
            rg.push_back({sum, -mn});
            r = i;
        }
    }

    reverse(lg.begin(), lg.end());
    reverse(rg.begin(), rg.end());

    int ch = a[k];
    while (true) {
        bool acted = false;
        if (!lg.empty() && ch >= lg.back().second) {
            ch += lg.back().first;
            lg.pop_back();
            acted = true;
        }
        if (!rg.empty() && ch >= rg.back().second) {
            ch += rg.back().first;
            rg.pop_back();
            acted = true;
        }
        if (lg.empty() || rg.empty()) {
            cout << yes << nl;
            return;
        }
        if (!acted) {
            cout << no << nl;
            return;
        }
    }
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t; cin >> t;
    while (t--)
        solve();
}