using namespace std;
#include <bits/stdc++.h>
#define int long long
#define nl '\n'

void solve() {
    string s; cin >> s;
    int n = s.size();
    bool a[s.size()] = {};
    for (int i = 0; i < s.size(); i++)
        a[i] = s[i] == 'M';

    int ans = INT_MAX;

    for (int i = 0; i < n - 2; i++) {
        if (!a[i + 1]) {
            int c_ans = a[i + 2] + !a[i];
            c_ans += i + (n - i - 3);
            ans = min(ans, c_ans);
        } 
    }

    if (ans == INT_MAX)
        cout << -1 << nl;
    else cout << ans << nl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);
    
    int t; cin >> t;
    while (t--)
        solve();
}