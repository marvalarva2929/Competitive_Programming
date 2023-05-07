#include <bits/stdc++.h>
using namespace std;
#define nl '\n'
#define f first
#define s second
#define int long long
#define MAX (int)1e5 + 10
int a[MAX];
int b[MAX];
bool vis[20];
set<int> adj[20];

void solve() {
    int n; cin >> n;
    bool no = false;
    for (int i = 0; i < n; i++) {
        char c; cin >> c;
        a[i] = c-'a';
    }
    for (int i = 0; i < n; i++) {
        char c; cin >> c;
        b[i] = c-'a';
        if (a[i] > b[i])    
            no = true;
    }
    if (no) {
        cout << -1 << nl;
        return;
    }
    set<int> empty;

    memset(vis, 0, sizeof(vis));
    for (int i = 0; i < 20; i++)
        adj[i] = empty;


    function<void(int)> dfs = [&](int x) {
        vis[x] = true;
        for (int next : adj[x])
            if (!vis[next])
                dfs(next);
    };

    for (int i = 0; i < n; i++) 
        if (a[i] != b[i])
            adj[a[i]].insert(b[i]), adj[b[i]].insert(a[i]);

    int ans = 20;

    for (int i = 0; i < 20; i++)
        if (!vis[i])
            dfs(i), ans--;

    cout << ans << nl;
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    int t; cin >> t;
    while (t--)
        solve();
}