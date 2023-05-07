using namespace std;
#include <bits/stdc++.h>
#define int long long
#define nl '\n'
#define no "no"
#define yes "yes"
#define print(x, y, z) for (int i = y; i <= z; i++) {cout << x[i] << " ";} cout << nl;
#define pi pair<int, int>
#define ff first 
#define ss second

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

const int mxn = 2e5;
vector<int> adj[mxn];
int prevv[mxn];
int vis[mxn];
int n, m, s;

pi dfs(int c, int t, int p) {
    pi ret = {-1, -1};
    if (vis[c] && vis[c] != t) {
        return {c, p};
    }
    prevv[c] = p;
    vis[c] = t;

    for (int nex : adj[c]) {
        if (vis[nex] && vis[nex] != t && nex != s) {
            return make_pair(nex, c);
        }
    }

    for (int nex : adj[c])
        if (!vis[nex] && nex != s) {
            pi x =  dfs(nex, t, c);
            if (x.ff != -1) 
                return x;
        }
    return ret;
}

void solve() {
    cin >> n >> m >> s;
    --s;
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        --u, --v;
        adj[u].push_back(v);
    }

    int clusters = 0;
    for (int nex : adj[s]) {
        pi x = dfs(nex, ++clusters, s);
        if (x.ff != -1) {
            cout << "Possible" << nl;
            vector<int> path1, path2;

            int p1 = x.ss;
            int p2 = prevv[x.ff];

            path1.push_back(x.ff);
            path2.push_back(x.ff);

            while (p1 != s) {
                path1.push_back(p1);
                p1 = prevv[p1];
            }

            while (p2 != s) {
                path2.push_back(p2);
                p2 = prevv[p2];
            }

            path1.push_back(s);
            path2.push_back(s); 

            reverse(path1.begin(), path1.end());
            reverse(path2.begin(), path2.end());

            cout << path1.size() << nl;
            for (int i : path1)
                cout << i + 1 << " ";
            cout << nl;
            cout << path2.size() << nl;
            for (int i : path2)
                cout << i + 1 << " ";
            cout << nl;
            return;
        }
    }   

    cout << "Impossible" << nl;
    return;
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t = 1;
    while (t--)
        solve();
}