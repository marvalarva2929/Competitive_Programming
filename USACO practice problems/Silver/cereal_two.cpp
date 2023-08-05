#include <bits/stdc++.h>
#define int long long
#define nl " \n"
#define pi pair<int, int>
#define ff first
#define ss second

using namespace std;
const int mxn = 1e5;
pi a[mxn];
bool vis[mxn], vis2[mxn];
vector<array<int, 3>> adj[mxn];
vector<int> ans;
int fir;
int ig;

void comp(int x, int prv = -1) {
    vis[x] = 1;
    for (auto& [a, b, c] : adj[x])
        if (vis[a]) {
            if (fir == -1 && vis[a] && a != prv) { 
                ig = c;
           
                if (b) fir = a;
                else fir = x;
                
                ans.push_back(c);
            }
        } else comp(a, x);
}

void dfs(int x) {
    vis2[x] = 1;
    for (auto& [a, b, c] : adj[x]) 
        if (ig != c && !vis2[a]) {
            ans.push_back(c);
            dfs(a);
        }
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int n, m; cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int a, b; cin >> a >> b; --a, --b;
        adj[a].push_back({b, 0, i});
        adj[b].push_back({a, 1, i});
    }
    
    for (int i = 0; i < m; i++) {
        if (!vis[i]) {
            fir = ig = -1;
            comp(i);

            if (fir != -1) dfs(fir);
            else dfs(i);
        }
    }
    
    cout << n - ans.size() << endl;
 
    set<int> ms;
    for (int x : ans)
        ms.insert(x);

    for (int i = 0; i < n; i++)
        if (!ms.count(i))
            ans.push_back(i);

    for (int x : ans)
        cout << x + 1 << endl;
}
