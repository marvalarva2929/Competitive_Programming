using namespace std;
#include <bits/stdc++.h>
#define int long long
#define nl '\n'
#define MAX (int)2e5 + 10
int pref[6][MAX] = {}; // 0 for abc, 1 for bca, 3 for cab

int other(int a, int b) {
    for (int i = 0; i < 3; i++)
        if (i != a && i != b)
            return i;
}

void solve() {
    int n, m; cin >> n >> m;
    string s; cin >> s;
    string t = "abc";
    
    int cur = 0;
    do {
        for (int i = 0; i < n; i++)
            pref[cur][i + 1] = (s[i] != t[i % 3]) + pref[cur][i];
        cur++;
    } while (next_permutation(t.begin(), t.end()));
    
    for (int i = 0; i < m; i++) {
        int l, r; cin >> l >> r;
        int ans = INT_MAX;
        for (int j = 0; j < 6; j++)
            ans = min(ans, pref[j][r] - pref[j][l - 1]);
        cout << ans << nl;
    }
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t = 1;
    while (t--)
        solve();
}