#include <bits/stdc++.h>
#define int long long
#define pi pair<int, int>
#define ff first
#define ss second
#define nl " \n"

using namespace std;
const int mxn = 2e5;
vector<pi> adj[mxn];
vector<int> loc[mxn];
int a[mxn], ans[mxn];
bool vis[mxn];

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int n, t; cin >> n >> t;
    
    for (int i = 0; i < t; i++) {
        int mi; cin >> mi;
        for (int j = 0; j < mi; j++) {
            int a, b; cin >> a >> b; --a, --b;
            adj[a].emplace_back(b, i), adj[b].emplace_back(a, i); 
        }
    }
    
    int k; cin >> k;
    for (int i = 0; i < k; i++) {
        cin >> a[i], a[i]--;
        loc[a[i]].push_back(i); 
    }
    
    fill(ans, ans + n, LLONG_MAX);
    ans[0] = 0; 

    priority_queue<pi, vector<pi>, greater<pi>> pc;
    for (pi nex : adj[0]) {
        int t = nex.ff, c = nex.ss;
        auto it = lower_bound(loc[c].begin(), loc[c].end(), 0);
        if (it != loc[c].end())
            pc.push({*it + 1, t});
    }
    
    vector<int> bnd(t, 0);

    while (pc.size()) {
        pi cur = pc.top();
        pc.pop();
        if (vis[cur.ss]) continue;
        ans[cur.ss] = cur.ff;
        vis[cur.ss] = 1;
        
        for (pi nex : adj[cur.ss]) {
            int t = nex.ff, c = nex.ss;
            if (vis[t]) continue;
            
            while (bnd[c] < loc[c].size() && loc[c][bnd[c]] < ans[cur.ss]) bnd[c]++;
            //auto it = lower_bound(loc[c].begin(), loc[c].end(), ans[cur.ss]);
            if (bnd[c] != loc[c].size() && (loc[c][bnd[c]] + 1 < ans[t]))
                pc.push({loc[c][bnd[c]] + 1, t});
        }    
    }

    cout << (ans[n - 1] == LLONG_MAX ? -1 : ans[n -1]) << nl;
}
