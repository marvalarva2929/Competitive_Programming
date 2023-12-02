using namespace std;
#include <bits/stdc++.h>
#define int long long
#define nl '\n'

const int mxn = (int)2.5e3 + 10;
int a[mxn];
vector<int> adj[mxn];
int n;

bool isPossible(int s) {
    vector<int> c_a(a, a + n + 1);
    auto dfs = [&c_a](int cur, int par, auto && dfs) -> void {
        for (int next : adj[cur])
            if (next != par)
                dfs(next, cur, dfs);
        c_a[par] = (c_a[par] + (12 - c_a[cur])) % 12;
    };
    dfs(s, 0, dfs);
    return (c_a[s] == 0 || c_a[s] == 1);
}

signed main() {
    ifstream cin("clocktree.in");
    ofstream cout("clocktree.out");
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 0; i < n - 1; i++) {
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
        ans += isPossible(i);
    cout << ans << nl;
    return 0;
}
