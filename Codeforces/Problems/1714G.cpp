using namespace std;
#include <bits/stdc++.h>
#define int long long
#define nl '\n'
#define no "no"
#define yes "yes"
#define print(x, y, z) for (int i = y; i <= z; i++) {cout << x[i] << " ";} cout << nl;

const int mxn = (int)2e5 + 10;

vector<int> next_[mxn];
int ans[mxn];
int a[mxn];
int b[mxn];

void dfs(int x, vector<int> & path, int lb, int la) {
    int c_lb = lb + b[x];
    int c_la = la + a[x];
    if (x > 1) { path.push_back(c_lb); }

    for (int next : next_[x]) { dfs(next, path, c_lb, c_la); }

    if (x > 1) { ans[x] = (upper_bound(path.begin(), path.end(), c_la) - path.begin()); }
    path.pop_back();
}

void solve() {
    int n; cin >> n;
    fill(next_, next_ + n + 5, vector<int>());
    for (int i = 2; i <= n; i++) {
        int p, aa, bb; cin >> p >> aa >> bb;
        next_[p].push_back(i);
        a[i] = aa;
        b[i] = bb;
    }

    vector<int> init;

    dfs(1, init, 0, 0);

    for (int i = 2; i <= n; i++)
        cout << ans[i] << " ";
    cout << nl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t; cin >> t;
    while (t--)
        solve();
}