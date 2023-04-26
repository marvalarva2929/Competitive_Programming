using namespace std;
#include <bits/stdc++.h>
#define int long long
#define nl '\n'
#define v2 vector<vector<int>>

class SCC { 
    private:

    v2 m_adj, m_rev;
    int m_n;
    vector<int> component_of;
    vector<int> finishing_times;
    vector<int> vis;
    
    void dfs_reverse(int x) {
        vis[x] = true;
        for (int xx : m_rev[x])
            if (!vis[xx])
                dfs_reverse(xx);
        finishing_times.push_back(x);
    }

    void dfs(int comp, int x) {
        component_of[x] = comp;
        for (int xx : m_adj[x])
            if (!component_of[xx]) 
                dfs(comp, xx);
    }

    public:

    SCC(v2 adj, v2 rev, int n) {
        m_n = n;
        m_adj = adj;
        m_rev = rev;
        component_of.resize(n + 1);
        vis.resize(n + 1);
    }

    vector<int> find() {

    for (int i = 1; i <= m_n; i++)
        if (!vis[i])
            dfs_reverse(i);

    int comp = 1;

    for (int i = finishing_times.size() - 1; i >= 0; i--) 
        if (!component_of[finishing_times[i]]) 
            dfs(comp++, finishing_times[i]);
        

        return component_of;
    }
};

signed main() {
    auto start = chrono::high_resolution_clock::now();

    ifstream fin("sat.txt");
    ofstream fout("sat.out");

    int n; fin >> n;
    v2 adj(2 * n + 1, vector<int>()), rev(2 * n + 1, vector<int>());

    for (int i = 0; i < n; i++) {
        int x, y, nx, ny; fin >> x >> y; // 1, 2
        if (x < 0) x = -x + n, nx = x - n;
        else nx = x + n;
        if (y < 0) y = -y + n, ny = y - n;
        else ny = y + n;
        
        adj[nx].push_back(y);
        adj[ny].push_back(x);
        rev[x].push_back(ny);
        rev[y].push_back(nx);
    }

    SCC scc = SCC(adj, rev, 2 * n);
    vector<int> component_of = scc.find();

    bool ans[n] = {};

    for (int i = 1; i <= n; i++) {
        if (component_of[i] == component_of[i + n]) {
            auto end = chrono::high_resolution_clock::now();
            cout << "Took " << chrono::duration_cast<chrono::milliseconds>(end - start).count() << "ms" << nl;
            cout << "NO" << nl;
            return 0;
        }
        ans[i - 1] = component_of[i] < component_of[i + n];
    }

    cout << "YES" << nl;

    for (int i : ans)
        cout << i;
    cout << nl;
    
    auto end = chrono::high_resolution_clock::now();

    cout << "Took " << chrono::duration_cast<chrono::milliseconds>(end - start).count() << "ms" << nl;
}