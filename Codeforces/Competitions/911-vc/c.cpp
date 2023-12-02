#include <bits/stdc++.h>
#define int long long
#define nl " \n"
#define pi pair<int, int>
#define ff first
#define ss second

using namespace std;
const int mxn = 3e5;
string s;
pi a[mxn];

int dfs(int x) {
    if (x == -1) return INT_MAX;

    if (max(a[x].ff, a[x].ss) == -1) return 0;
    
    int ans = min(dfs(a[x].ff) + (s[x] != 'L'), dfs(a[x].ss) + (s[x] != 'R'));
    return ans;
}

void solve() {
    int n; cin >> n;
    cin >> s;

    for (int i = 0; i < n; i++)
        cin >> a[i].ff >> a[i].ss, a[i].ff--, a[i].ss--;
    
    int ans = dfs(0);

    cout << ans << nl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t; cin >> t;
    while (t--)
        solve();
}
