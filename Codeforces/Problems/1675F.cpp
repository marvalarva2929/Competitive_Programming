using namespace std;
#include <bits/stdc++.h>
#define int long long
#define nl '\n'
#define no "no"
#define yes "yes"
#define print(x, y, z) for (int i = y; i <= z; i++) {cout << x[i] << " ";} cout << nl;

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

int n, k, x, y;

void solve() {  
    cin >> n >> k >> x >> y;
    vector<int> adj[n] = {};
    bool toVis[n] = {};
    x--, y--;

    for (int i = 0; i < k; i++)
        { int x; cin >> x; toVis[--x] = true; }

    for (int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int last[n + 1];
    queue<pair<int, int>> pc;
    pc.push({-1, x});

    while (pc.size()) {
        int cur = pc.front().second;
        int prev = pc.front().first;
        pc.pop();
        last[cur] = prev;
        for (int nex : adj[cur])
            if (nex != prev)
                pc.push({cur, nex});
    }

    toVis[x] = toVis[y] = true;

    int w = -1;

    int ans = 0;

    set<int> path;
    path.insert(x);
    path.insert(y);

    int idx = y;
    while (idx != -1) {
        w++;
        path.insert(idx);
        toVis[idx] = false;
        idx = last[idx];
    }

    for (int i = 0; i < n; i++) {
        if (toVis[i]) {
            int idx = i;
            while (idx != -1 && path.count(idx) == 0  ) {
                path.insert(idx);
                idx = last[idx];
            }   
        }
    }


    ans = (path.size() - 1) * 2;
    ans -= w;
    cout << max((int)0, (int)ans) << nl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t; cin >> t;
    while (t--)
        solve();
}