#include <bits/stdc++.h>
#define int long long
#define nl " \n"
#define pi pair<int, int>
#define ff first
#define ss second

using namespace std;
const int mxn = 2e5;

vector<int> adj[mxn], ord;
bool col[mxn], vis[mxn]; 
int par[mxn], deg[mxn];
int a[mxn];

signed main() {
    cin.tie(0)->sync_with_stdio(false);
    int n; cin >> n;

    for (int i = 0; i < n; i++)
        cin >> a[i], adj[--a[i]].push_back(i), deg[a[i]]++;
   
    queue<int> ck;
    for (int i = 0; i < n; i++)
        if (deg[i] == 0) ck.push(i);

    while (ck.size()) {
        int cur = ck.front(); ck.pop();
        
        if (!col[a[cur]]) {
            if (!col[cur]) {
                col[a[cur]] = 1;
                deg[a[cur]] = 0;
                ck.push(a[cur]);
            } else if (!(--deg[a[cur]])) ck.push(a[cur]);
        }
    }
    
    for (int i = 0; i < n; i++)
        if (deg[i]) {
            for (int j = i; deg[j]; j = a[j])
                col[a[j]] = !col[j], deg[j] = 0;
            
            if (col[i]) {
                cout << -1 << nl;
                return 0;
            }
        }

    vector<int> ans;
    for (int i = 0; i < n; i++)
        if (!col[i]) ans.push_back(a[i] + 1);
    
    cout << ans.size() << nl;
    for (int x : ans)
        cout << x << " ";
    cout << nl;
}
