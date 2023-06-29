#include <bits/stdc++.h>
#define int long long
#define nl " \n"
#define pi pair<int, int>
#define ff first
#define ss second
#define x first
#define y second

using namespace std;

const int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};

const int mxn = 2e5;
vector<pi> aa;
map<pi, pi> ans;

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int n; cin >> n;
    
    set<pi> in;

    for (int i = 0; i < n; i++) {
        int u, v; cin >> u >> v;
        aa.emplace_back(u, v);
        in.insert({u, v}); 
    }
  
    queue<pi> pc;

    for (pi p : aa) {
        for (int i = 0; i < 4; i++) {
            pi np = {dx[i] + p.x, dy[i] + p.y}; 
            
            if (!in.count(np)) {
                pc.push(p);
                ans[p] = np;
                break;
            }
        }
    }
    while (pc.size()) {
        pi p = pc.front();  
        pc.pop();
       
        for (int i = 0; i < 4; i++) {
            int nx = dx[i] + p.x,
                ny = dy[i] + p.y;
            pi np = {nx, ny};

            if (in.count(np) && !ans.count(np)) {
                pc.push(np);
                ans[np] = ans[p];
            } 
        }
    }
   
    for (pi& p : aa) {
        pi ret = ans[p];
        cout << ret.ff << " " << ret.ss << nl; 
    }
}
