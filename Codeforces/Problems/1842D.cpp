#include <bits/stdc++.h>
#define int long long
#define nl " \n"
#define pi pair<int, int>
#define ff first
#define ss second

using namespace std;

const int mxn = 100;
vector<int> adj[mxn];
vector<pair<string, int>> ans;
int dist[mxn][mxn];
bool cur[mxn];

signed main() {
    cin.tie(0)->sync_with_stdio(false);
    
    memset(cur, 1, sizeof cur);

    int n, m; cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v, y; cin >> u >> v >> y; --u, --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        dist[u][v] = dist[v][u] = y; 
    }
    
    cur[n - 1] = 0;
    int t = 0;

    while (cur[0]) {
        int mn = INT_MAX;
        for (int i = 0; i < n; i++)
            if (!cur[i])
                for (int& nex : adj[i])
                    if (cur[nex])
                        mn = min(mn, dist[i][nex]); 
 
   //     for (int i = 0; i < n; i++)
   //         cout << cur[i] << (i == n - 1 ? nl : " ");
   //     
   //     for (int i = 0; i < n; i++)
   //         for (int j = i + 1; j < n; j++)
   //             if (dist[i][j])
   //                 cout << i << " " << j << " : " << dist[i][j] << nl;
        
        if (mn == INT_MAX) { cout << "inf" << nl; return 0; };
        
        t += mn;
        string s;
        for (int i = 0; i < n; i++)
            s.push_back(cur[i] ? '1' : '0');
        ans.emplace_back(s, mn);

        for (int i = 0; i < n; i++)
            if (!cur[i])
                for (int& nex : adj[i])
                    if (cur[nex]) {
                        dist[i][nex] -= mn;
                        dist[nex][i] -= mn;
                    }
        
        for (int i = 0; i < n; i++)
            if (!cur[i])
                for (int&nex : adj[i])
                    if (cur[nex] && !dist[i][nex])
                        cur[nex] = 0;
    }
    
    cout << t << " " << ans.size() << nl;
    for (auto [s, t] : ans)
        cout << s << " " << t << nl;
}
