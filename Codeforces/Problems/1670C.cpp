using namespace std;
#include <bits/stdc++.h>
#define int long long
#define nl '\n'
#define MAX (int)1e5 + 10
#define mod (int)1000000007

int a[MAX], b[MAX], d[MAX];
vector<int> adj[MAX];
bool vis[MAX];

bool dfs(int x) {
    // cout << x  << " " << d[x] << nl;
    vis[x] = true;
    bool ans = 1;
    ans &= d[x] == 0;
    for (int xx : adj[x])
        if (!vis[xx])
            ans &= dfs(xx);

    return ans;
}

int power(int a, int n) {
    int ans = 1;
    while (n) {
        if (n & 1)
            ans = (ans * a % mod);
        n >>= 1;
        a = (a * a % mod);
    }
    return ans;
}

void solve() {
    int n; cin >> n;
    fill(d, d + n + 2, 0);
    fill(vis, vis + n + 1, 0);

    for (int i = 1; i <= n; i++)
        adj[i].clear();

    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        d[x] = true;
    }
    for (int i = 0; i < n; i++) {
        if (a[i] == b[i])
            d[a[i]] = true;
        adj[a[i]].push_back(b[i]);
    }

    // cout << 'a' << nl;

    int f = 0;
    for (int i = 1; i <= n; i++)
        if (!vis[i])
            if (dfs(i))
                f++;

    cout << power(2, f) << nl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t; cin >> t;
    while (t--)
        solve();
}
