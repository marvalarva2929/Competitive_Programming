using namespace std;
#include <bits/stdc++.h>
#define int long long
#define nl '\n'
#define max(x, y) max((int)x, (int)y)
#define min(x, y) min((int)x, (int)y)
#define MAX (int)2e5 + 10
vector<int> rev[MAX] = {};
int sz[MAX] = {}, vis[MAX] = {};
vector<int> last;

void dfs (int x) {
    sz[x] = vis[x] = 1;
    for (int next : rev[x])
        dfs(next),
        sz[x] += sz[next];
};  

int in(int x, int l, int r) {
    x = min(x, r);
    if (x <= l) x = r;
    return x;
}

void solve() {
    int n; cin >> n;
    fill(rev, rev + n + 5, vector<int>());
    fill(sz, sz + n + 6, 0);
    fill(vis, vis + n + 5, 0);
    last = vector<int>();
    int a[n + 2] = {};
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    
    for (int i = 1; i <= n; i++) {
        int next = a[i] + i;
        next = in(next, 0, n + 1);
        rev[next].push_back(i);
    }

    dfs(n + 1);

    // for (int i = 1; i <= n; i++)
        // cout << i << " " << vis[i] << nl;

    if (vis[1]) {
        int ans = n * ((2 * n) + 1);
        int i = 1;
        do {
            ans -= sz[i] + (n - sz[n + 1]) + 1;
            i = in(a[i] + i, 0, n + 1);
        } while (i != n + 1);
        cout << ans << nl;
    } else {
        int ans = 0;
        int i = 1;
        do {
            ans += sz[n + 1] + n;
            vis[i] = 2;
            i = in(a[i] + i, 0, n + 1);
        } while (vis[i] != 2);
        cout << ans << nl;
    }
    return;
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t; cin >> t;
    while (t--)
        solve();
}