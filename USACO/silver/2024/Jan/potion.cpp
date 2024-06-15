#include <bits/stdc++.h>
#define int long long
#define nl " \n"
#define pi pair<int, int>
#define ff first
#define ss second

using namespace std;
const int mxn = 1e5;
int a[mxn], h[mxn], t[mxn];
vector<int> adj[mxn];
int ans = 0;

int dfs(int c, int p, int o) {
    o = h[c];
    
    int m = 0;

    for (int n : adj[c])
        if (n != p)
            m += dfs(n, c, 0);
    if (adj[c].size() == 1) m++;

    int t = min(m, o);
    
    m -= t;
    ans += t;
    
    //cout << c << " : " << m << " " << o << nl;

    return m;
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int n; cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i], --a[i];

    for (int i = 0; i < n - 1; i++) {
        int a, b; cin >> a >> b; --a, --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    int lvs = 0;
    for (int i = 1; i < n; i++)
        lvs += adj[i].size() == 1;
    
    for (int i = 1; i <= lvs; i++)
        h[a[i - 1]]++;
    
    dfs(0, -1, 0);
    
    cout << ans << endl;
}
