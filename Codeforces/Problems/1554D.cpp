#include <bits/stdc++.h>
#define int long long
#define nl '\n'

using namespace std;

void solve() {
    int n; cin >> n;

    string ans;
    ans.resize(n);

    for (int i = 0; i < n/2; i++)
        ans[i] = 'a';
    for (int i = n - (n/2 - 1); i < n; i++)
        ans[i] = 'a';

    if (n % 2)
        ans[n/2] = 'b', ans[n/2 + 1] = 'c';
    else ans[n/2] = 'b';

    cout << ans << nl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t; cin >> t;
    while (t--)
        solve();
}
