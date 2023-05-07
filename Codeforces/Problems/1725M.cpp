using namespace std;
#include <bits/stdc++.h>
#define int long long
#define nl '\n'
#define no "no"
#define yes "yes"
#define print(x, y, z) for (int i = y; i <= z; i++) {cout << x[i] << " ";} cout << nl;

const int mxn = (int)1e5 + 10;

struct Node {
    int score = 0;
    bool rev;
    int n;
    Node(int nn, int sc, bool rrev) {
        score = sc;
        rev = rrev;
        n = nn;
    }
    friend bool operator<(const Node & a, const Node & b) {
        return a.score > b.score;
    }
};


vector<pair<pair<int, int>, bool>> adj[mxn][2]; // outgoing edge, weight, reversed
int path[mxn];
bool vis[mxn][2];

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

void solve() {
    int n, m; cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int u, v, w; cin >> u >> v >> w;
        adj[u][0].push_back({{v, w}, 0});
        adj[v][1].push_back({{u, w}, 1});
    }

    for (int i = 1; i <= n; i++)
        adj[i][0].push_back({{i, 0}, 1});

    priority_queue<Node> pq;
    Node init(1, 0, 0);
    pq.push(init);
    fill(path, path + n + 5, LLONG_MAX);

    while (pq.size()) {
        Node cur = pq.top();
        pq.pop();
        if (!vis[cur.n][cur.rev]) {
            // cout << cur.n << " " << cur.rev << nl;  
            vis[cur.n][cur.rev] = true;
            path[cur.n] = min(path[cur.n], cur.score);
            for (auto edge : adj[cur.n][cur.rev]) {
                if (!vis[edge.first.first][edge.second]) {
                    Node next(edge.first.first, cur.score + edge.first.second, edge.second);
                    pq.push(next);
                }
            }   
        }
    }


    for (int i = 2; i <= n; i++)
        cout << (path[i] == (int)LLONG_MAX ? -1 : path[i]) << " ";
    cout << nl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t = 1;
    while (t--)
        solve();
}