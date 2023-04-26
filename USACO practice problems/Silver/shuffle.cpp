using namespace std;
#include <bits/stdc++.h>
#define int long long
#define nl '\n'

const int mxn = 1e5 + 10;
vector<int> adj[mxn];
vector<int> rev[mxn];

class SCC {
    private:
    vector<int> finishing_times;
    vector<vector<int>> comps;
    int num_of_components = 0;
    int N;

    void dfs(int x, int c, vector<bool> & vis) {
        vis[x] = true;
        // cout << c << nl;
        comps[c].push_back(x);
        for (int nex : adj[x])
            if (!vis[nex])
                dfs(nex, c, vis);
            // else cout << nex << nl;
    }

    void dfs_rev(int x, vector<bool> & vis) {
        if (vis[x]) return;
        vis[x] = true;
        for (int nex : rev[x])
            if (!vis[nex])
                dfs_rev(nex, vis);
        finishing_times.push_back(x);
    }

    public: 
    SCC(int toN) {
        N = toN;
        comps.resize(N + 1);
        find();
    }

    void find() {
        vector<bool> vis(N + 1);
        for (int i = 1; i <= N; i++)
            if (!vis[i])
                dfs_rev(i, vis);
        reverse(finishing_times.begin(), finishing_times.end());
        // cout << 'e' << nl;
        fill(vis.begin(), vis.end(), 0);
        for (int finish : finishing_times) {
            if (!vis[finish])
                // cout << finish << " : ",
                dfs(finish, ++num_of_components, vis);
        }
        // cout << 'd' << nl;
    }
    
    set<vector<int>> getSCCS() {
        set<vector<int>> ret;
        for (int i = 1; i <= num_of_components; i++) {
            if (comps[i].size() > 1)
                ret.insert(comps[i]);
        }
        return ret;
    }
};

signed main() {
    ifstream cin("shuffle.in");
    ofstream cout("shuffle.out");
    int n; cin >> n;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        ans += (i == x);
        adj[i].push_back(x);
        rev[x].push_back(i);
    }
    SCC s(n);
    set<vector<int>> sccs = s.getSCCS();
    for (auto scc : sccs) {
        ans += scc.size();
    }
    cout << ans << nl;
}