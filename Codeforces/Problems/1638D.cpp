#include <bits/stdc++.h>
#define int long long
#define nl " \n"
#define pi pair<int, int>
#define ff first
#define ss second

using namespace std;
const int mxn = 1000;
int a[mxn][mxn], b[mxn][mxn];
vector<pair<int, pi>> ans;
int n, m;

int same(pi x) {
    int last = -1;
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            if (b[x.ff + i][x.ss + j] == -1) {
                if (last == -1) last = a[x.ff + i][x.ss + j];
                else if (a[x.ff + i][x.ss + j] != last) return -1;
            }
    return last;
}

void fl(pi x) {
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            b[x.ff + i][x.ss + j] = a[x.ff + i][x.ss + j];
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    cin >> n >> m;
    
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> a[i][j], b[i][j] = -1;
    
    queue<pi> pc;

    for (int i = 0; i < n - 1; i++) 
        for (int j = 0; j < m - 1; j++) {
            int ret = same({i, j}); 
            if (b[i][j] == -1 && ret != -1)   
                pc.push({i, j}), fl({i, j}), ans.push_back({ret, {i, j}});

        }
    //for (int i = 0; i < n; i++)
    //    for (int j = 0; j < m; j++)
    //        cout << b[i][j] << nl[j == m - 1];
    while (pc.size()) {
        pi cur = pc.front();
        pc.pop();
        //cout << cur.ff << " " << cur.ss << nl;
        for (int i = -1; i < 2; i++)
            for (int j = -1; j < 2; j++) {
                int nx = cur.ff + i, ny = cur.ss + j;
                if (nx < 0 || nx >= n - 1 || ny < 0 || ny >= m - 1) continue;
                int ret = same({nx, ny});
                //cout << nx << " " << ny << " : " << ret << nl;
                vector<pi> adj;
                if (ret != -1) pc.push({nx, ny}), adj.push_back({nx, ny}), ans.push_back({ret, {nx, ny}});
                for (pi x : adj)
                    fl(x);
            }
    }
    
    //for (auto x : ans)
    //    cout << x.ff << " : " << x.ss.ff << " " << x.ss.ss << nl;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (b[i][j] == -1) {
                cout << -1 << nl;
                return 0;
            }
    
    reverse(ans.begin(), ans.end());
    cout << ans.size() << nl;
    for (auto & x : ans)
        cout << x.ss.ff + 1 << " " << x.ss.ss + 1 << " " << x.ff << nl;
}
