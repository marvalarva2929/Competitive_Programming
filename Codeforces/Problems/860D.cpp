using namespace std;
#include <bits/stdc++.h>
#define int long long
#define nl '\n'
#define no "no"
#define yes "yes"
#define print(x, y, z) for (int i = y; i <= z; i++) {cout << x[i] << " ";} cout << nl;
#define pi pair<int, int>
#define f first
#define s second
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

const int mxn = 2e5 + 10;
vector<pair<int, pi>> ans;
vector<int> adj[mxn];
bool vis[mxn];

bool dfs(int x, int par) {
    vis[x] = true;
    set<int> verts;
    
    for (int nex : adj[x])
        if (!vis[nex])
            verts.insert(nex);

    for (int nex : adj[x])
        if (!vis[nex] && nex != par)
            if (dfs(nex, x))
                verts.erase(nex);

    // for (int i : verts)
    //     cout << i << " ";

    bool ret = false;

    if ((verts.size() % 2) && par != 0) 
        verts.insert(par),
        ret = true;

    // cout << " : " << ret << nl;

    queue<int> all;
    for (int i : verts)
        all.push(i);
    while (all.size() > 1) {
        int w = all.front();
        all.pop();
        int y = all.front();
        all.pop();
        ans.push_back({w, {x, y}});
    }

    return ret;
}

void solve() {
    int n, m; cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }   

    for (int i = 1; i <= n; i++)
        if (!vis[i]) {
            // cout << i << " : ";
            dfs(i, 0);
            // cout << nl;
        }
        
    cout << ans.size() << nl;
    for (auto a : ans)
        cout << a.f << " " << a.s.f << " " << a.s.s << nl;

    
}

signed main() {
    // cin.tie(0)->sync_with_stdio(false);

    int t = 1;
    while (t--)
        solve();
}