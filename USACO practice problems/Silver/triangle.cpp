#include <bits/stdc++.h>
#define int long long
#define nl " \n"
#define pi pair<int, int>
#define ff first
#define ss second

using namespace std;
const int mxx = 2e4, mxn = 1e5, MOD = 1e9 + 7;
vector<int> nx[mxx+1], ny[mxx+1];
int tx[mxn], ty[mxn];
vector<pi> cy[mxn], cx[mxn];
pi a[mxn];

void solve() {
    ifstream cin("triangles.in");
    ofstream cout("triangles.out");
    //std::srand(std::time(nullptr));

    int n; cin >> n;
    //int n = ((int)rand()) % (int)10000 + 3;

    fill(tx, tx + n, -1);
    fill(ty, ty + n, -1);
    map<pi, int> wy;
    
    set<int> ax, ay;
    for (int i = 0; i < n; i++) {
        cin >> a[i].ff >> a[i].ss;
        //a[i].ff = ((int)rand()) % 20000, a[i].ss = ((int)rand()) % 20000; 
        a[i].ff += 1e4, a[i].ss += 1e4; 
        nx[a[i].ff].push_back(a[i].ss), ny[a[i].ss].push_back(a[i].ff); 
        ax.insert(a[i].ff), ay.insert(a[i].ss);
    }

    int cntx = 0;
    for (int x : ax) {
        tx[x] = cntx, sort(nx[x].begin(), nx[x].end());
        int c = nx[x].size() - 1;

        cx[cntx] = vector<pi>(nx[x].size());
        for (int i = 1; i < nx[x].size(); i++)
            cx[cntx][0].ff = cx[cntx][0].ff % MOD + ((c--) * (nx[x][i] - nx[x][i - 1]) % MOD) % MOD;
        for (int i = 1; i < nx[x].size(); i++)
            cx[cntx][i].ff = cx[cntx][i - 1].ff % MOD - ((nx[x][i] - nx[x][i - 1]) * (nx[x].size() - i) % MOD) % MOD,
            cx[cntx][i].ss = cx[cntx][i - 1].ss % MOD + ((nx[x][i] - nx[x][i - 1]) * i % MOD) % MOD;
        
        //cout << x << " : " << nl;
        //for (int i = 0; i < nx[x].size(); i++)
        //    cout << cx[cntx][i].ff << " " << cx[cntx][i].ss << nl;
        //cout << nl;

    
        cntx++;
    }
    
    //cout << nl;

    int cnty = 0;
    for (int x : ay) {
        ty[x] = cnty, sort(ny[x].begin(), ny[x].end());
        int c = ny[x].size() - 1;

        cy[cnty] = vector<pi>(ny[x].size());
        for (int i = 1; i < ny[x].size(); i++)
            cy[cnty][0].ff = cy[cnty][0].ff % MOD + ((c--) * (ny[x][i] - ny[x][i - 1]) % MOD) % MOD;
        for (int i = 1; i < ny[x].size(); i++)
            cy[cnty][i].ff = cy[cnty][i - 1].ff % MOD - ((ny[x][i] - ny[x][i - 1]) * (ny[x].size() - i) % MOD) % MOD,
            cy[cnty][i].ss = cy[cnty][i - 1].ss % MOD + (((ny[x][i] - ny[x][i - 1]) * i) % MOD) % MOD;
        
        for (int i = 0; i < ny[x].size(); i++)
            wy[{ny[x][i], x}] = i;

        //cout << x << " : " << nl;
        //for (int i = 0; i < ny[x].size(); i++)
        //    cout << cy[cnty][i].ff << " " << cy[cnty][i].ss << nl;
        //cout << nl;
        cnty++; 
    }
    
    //for (int i = 0; i < n; i++) {
    //    cout << a[i].ff << " : " << a[i].ss << nl;
    //    cout << wy[a[i]] << nl;
    //}
    //
    //return 0 ;
    int ans = 0;
    for (int x : ax) {
        int ttx = tx[x];
        for (int j = 0; j < nx[x].size(); j++) {
            int y = nx[x][j]; 
            int tty = ty[y]; 
            
            int t = (cx[ttx][j].ff + cx[ttx][j].ss) % MOD;
            int b = (cy[tty][wy[{x, y}]].ff + cy[tty][wy[{x, y}]].ss) % MOD; 
            
            //cout << x << " : " << y << nl;
            //cout << cx[ttx][j].ff << " " << cx[ttx][j].ss << nl;
            //cout << cy[tty][wy[{x, y}]].ff << " " <<  cy[tty][wy[{x, y}]].ss << nl;
            //cout << t << " " << b << nl;

            ans = ans % MOD + (t * b) % MOD;
        }
    }
    
    while (ans < 0) ans += MOD;
    cout << ans % MOD << endl;
    

    
    //int ans2 = 0;
    //for (int i = 0; i < n; i++) {
    //    int x = a[i].ff, y = a[i].ss;
    //    
    //    for (int j : nx[x]) 
    //        for (int k : ny[y])
    //            ans2 = ans2 +  (abs(y - j) * (abs(x - k))) % MOD;
    //}
    //
    //cout << ans2 %  MOD<< nl << nl;
}

signed main() {
        solve();
}


