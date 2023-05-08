using namespace std;
#include <bits/stdc++.h>
#define int long long
#define nl '\n'
#define pi pair<int, int>
#define ff first
#define ss second

const int mxn = 2e5;
vector<int> adj[mxn];
int dist[mxn];
int maxIn[mxn];
int n, k, c; 
int ans;

void dfs(int par, int cur) {
    for (int nex : adj[cur])
        if (nex != par) {
            dfs(cur, nex);
            maxIn[cur] = max(maxIn[cur], maxIn[nex] + 1);
        }
}

void answerDfs(int par, int cur, int mxDist) {
    int cost = dist[cur] * c;
    int prof = max(mxDist, maxIn[cur]) * k;

    // cout << cur << " " << prof << " " << cost << nl;

    ans = max(ans, prof - cost);

    int maxDist[2] = {-2, -2};
    for (int nex : adj[cur])
        if (nex != par) {
            if (maxIn[nex] >= maxDist[1])
                maxDist[0] = maxDist[1],
                maxDist[1] = maxIn[nex];
            else if (maxIn[nex] >= maxDist[0])
                maxDist[0] = maxIn[nex];
        }

    // cout << maxDist[0] << " : " << maxDist[1] << nl;

    for (int nex : adj[cur])
        if (nex != par) {
            int mx = (maxIn[nex] == maxDist[1] ? maxDist[0] : maxDist[1]); 
            answerDfs(cur, nex, max(mx + 2, mxDist + 1));
        }
}

void solve() {
    cin >> n >> k >> c;

    fill(adj, adj + n, vector<int>());
    fill(dist, dist + n, 0);
    fill(maxIn, maxIn + n, 0);

    for (int i = 0; i < n - 1; i++) {
        int v, w; cin >> v >> w; --v, --w;
        adj[v].push_back(w);
        adj[w].push_back(v);
    }

    // BFS to find distances from each node to node 0
    queue<pi> pc;
    pc.push({-1, 0});

    while (pc.size()) {
        int prv = pc.front().ff;
        int cur = pc.front().ss;
        pc.pop();

        if (prv != -1)
            dist[cur] = 1 + dist[prv];

        for (int nex : adj[cur])
            if (nex != prv)
                pc.push({cur, nex});
    }

    // DFS to find the farthest node in each node's subtree
    dfs(-1, 0);

    // DFS to find the answer for each node
    ans = 0;
    answerDfs(-1, 0, 0);

    cout << ans << nl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t; cin >> t;
    while (t --> 0)
        solve();
}