using namespace std;
#include <bits/stdc++.h>
#define int long long
#define nl '\n'

void solve() {
    int n; string ss; cin >> n >> ss;
    bool s[n];
    int last[2] = {};
    for (int i = 1; i < n; i++)
        s[i] = ss[i - 1]&1;

    for (int i = 1; i < n; i++) {
        last[s[i]] = i;
        if (s[i])
            cout << last[!s[i]] + 1 << " ";
        else    
            cout << last[!s[i]] + 1 << " ";
    }
    cout << nl;
    return;
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    int t; cin >> t;
    while(t--)
        solve();

    return 0;
}