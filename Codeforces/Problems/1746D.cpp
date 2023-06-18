#include <bits/stdc++.h>
#define int long long
#define nl '\n'
#define pi pair<int, int>
#define ff first
#define ss second

using namespace std;
const int mxn = 2e5;
vector<int> adj[mxn];
int s[mxn];

pi dfs(int cur, int num) {
    
    int left = adj[cur].size() ? num % adj[cur].size() : -1;
     
    pi ret = {num * s[cur], (num + 1) * s[cur]};
    
    vector<pi> schild;
    unordered_map<int, int> fchild;
    unordered_map<int, int> fschild;

    for (int nex : adj[cur]) {
        pi res = dfs(nex, num / adj[cur].size());
        schild.push_back({res.ss - res.ff, nex});    
        fchild[nex] = res.ff; 
        fschild[nex] = res.ss; 
    }
    sort(schild.begin(), schild.end(), greater<pi>());

    if (left != -1) {
        for (int i = 0; i < left; i++)
            ret.ff += fschild[schild[i].ss],
            ret.ss += fschild[schild[i].ss],
            fchild[schild[i].ss] = 0;
        
        ret.ss += fschild[schild[left].ss];

        for (auto &p : fchild)
            ret.ff += p.ss,
            ret.ss += p.ff != schild[left].ss ? p.ss : 0;
    }
    
    //cout << cur  + 1<< " " << num << " : "  << ret.ff << " " << ret.ss << nl;
    return ret;
}

void solve() {
    int n, k; cin >> n >> k;

    fill(adj, adj + n, vector<int>());

    for (int i = 0; i < n - 1; i++) {
        int x; cin >> x;
        adj[x - 1].push_back(i + 1);
    }
    
    for (int i = 0; i < n; i++)
        cin >> s[i];

    pi ans = dfs(0, k);

    cout << ans.ff << nl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);
    
    int t; cin >> t;
    while (t--)
        solve();
}
