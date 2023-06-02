#include <bits/stdc++.h>
#define int long long
#define nl '\n'

using namespace std;

bool dp[18][10][10][2][2]; // idx, mx, mn, greater, smaller
string beg, lim;
int ans;
string res;

void rec(int idx, string cur, int mx, int mn, bool greater, bool smaller) {
    if (idx == beg.size()) {
        if (mx - mn < ans) {
            ans = mx - mn;
            res = cur;
        }
        return; 
    }
    
    if (dp[idx][mx][mn][greater][smaller])
        return;
    dp[idx][mx][mn][greater][smaller] = 1;

    if (!greater && !smaller) {
        for (int i = beg[idx] - '0'; i <= lim[idx] - '0'; i++)
            rec(idx + 1, cur + ((char)(i + '0')), max(mx, i), min(mn, i), i > beg[idx] - '0', i < lim[idx] - '0');
    } else if (greater && !smaller) {
        for (int i = 0; i <= lim[idx] - '0'; i++) 
            rec(idx + 1, cur + ((char)(i + '0')), max(mx, i), min(mn, i), 1, i < lim[idx] - '0');
    } else if (!greater && smaller) {
        for (int i = beg[idx] - '0'; i <= 9; i++)
            rec(idx + 1, cur + ((char)(i + '0')), max(mx, i), min(mn, i), i > beg[idx] - '0', 1);
    } else {
        for (int i = 0; i <= 9; i++)
            rec(idx + 1, cur + ((char)(i + '0')), max(mx, i), min(mn, i), 1, 1);
    }
}

void solve() {
    cin >> beg >> lim;
    ans = 10;
    memset(dp, 0, sizeof dp);

    if (beg == lim) { cout << beg << nl; return; }
    if (beg.size() < lim.size()) {
        for (int i = 0; i < beg.size(); i++)
            cout << 9;
        cout << nl;
        return;
    }

    rec(0, "", 0, 10, 0, 0);
    cout << res << nl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t; cin >> t;
    while (t--)
        solve();
}
