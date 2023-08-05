using namespace std;
#include <bits/stdc++.h>
#define int long long
#define nl '\n'

const int mxn = 1e5 + 10;
int a[mxn];
vector<int> r[mxn];
int v[mxn];
bool vis[mxn];
vector<int> inComp[mxn];
int n;

class SCC {
    private:
        vector<int> finishing_times;

        void dfs_rev(int x) {
            vis[x] = true;
            for (int nex : r[x])
                if (!vis[nex])
                    dfs_rev(nex);
            finishing_times.push_back(x);
        }

        void dfs(int x, int c) {
            inComp[c].push_back(x);
            vis[x] = true;
            if (!vis[a[x]])
                dfs(a[x], c);
        }
        
    public:

    int comps = 0;
    SCC() {
        find();
    }

    void find() {
        for (int i = 1; i <= n; i++)
            if (!vis[i])
                dfs_rev(i);
        reverse(finishing_times.begin(), finishing_times.end());
        fill(vis, vis + n + 1, false);
        for (int finish : finishing_times) 
            if (!vis[finish])
                dfs(finish, ++comps);
    }
};  

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    cin >> n;
    int ans = 0;
    for (int i = 1; i <= n; i++) {   
        cin >> a[i] >> v[i];
        ans += v[i];
        r[a[i]].push_back(i);
    }

    SCC scc;

    for (int i = 1; i <= scc.comps; i++) {
        if (inComp[i].size() > 1) {
            int mn = LLONG_MAX;
            for (int co : inComp[i])
                mn = min(mn, v[co]);
            ans -= mn;
        }
    }

    cout << ans << nl;    
}
