using namespace std;
#include <bits/stdc++.h>
#define int long long
#define nl '\n'

const int mxn = (int)1e5 + 10;

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

struct pair_hash {
    size_t operator()(pair<int, int> x) const {
        return x.first ^ x.second;
    }
};

void solve() {
    int n, a, b; cin >> n >> a >> b;
    vector<pair<int, int>> adj[n + 1] = {};
    vector<bool> vis(n + 1);
    unordered_map<pair<int, int>, int, pair_hash> w;
    unordered_map<int, bool, custom_hash> poss;

    for (int i = 0; i < n - 1; i++) {
        int u, v, ww; cin >> u >> v >> ww;
        adj[u].push_back({v, ww});
        adj[v].push_back({u, ww});
    }

    queue<pair<int, int>> pc;
    pc.push({0, b});
    int path[n + 1] = {};

    while (pc.size()) {
        auto cur = pc.front(); 
        pc.pop();
        if (cur.first)
            poss[path[cur.second]] = true;
        // cout << cur.first << " " << cur.second << " : " << path[cur.second] << nl;
        for (auto next : adj[cur.second]) 
            if (next.first != cur.first) {
                pc.push({cur.second, next.first});
                path[next.first] = path[cur.second] ^ next.second;
            }
    }

    int path2[n + 1] = {};
    pc.push({0, a});
    while (pc.size()) {
        auto cur = pc.front(); 
        pc.pop();
        if (poss[(path2[cur.second])]) {
            cout << "YES" << nl;
            return;
        }
        for (auto next : adj[cur.second]) 
            if (next.first != cur.first && next.first != b) {
                pc.push({cur.second, next.first});
                path2[next.first] = path2[cur.second] ^ next.second;
            }

            
    }
    cout << "NO" << nl;
    return;
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t; cin >> t;
    while (t--)
        solve();
}