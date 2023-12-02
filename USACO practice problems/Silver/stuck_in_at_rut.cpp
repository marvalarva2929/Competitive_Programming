#include <bits/stdc++.h>
#define int long long
#define nl " \n"
#define pi pair<int, int>
#define ff first
#define ss second
#define xx ff.ff
#define yy ff.ss

using namespace std;
const int mxn = 1000;
pair<int, pi> a[mxn];
pi hit[mxn];
int ans[mxn];

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int n; cin >> n;
    fill(hit, hit + n, make_pair(LLONG_MAX, -1));
    vector<pair<pi, int>> Nn;
    vector<pair<pi, int>> Ee;

    for (int i = 0; i < n; i++) {
        char c; int x, y; 
        cin >> c >> x >> y;
        a[i] = {(c == 'N'), {x, y}};
        if (a[i].ff) Nn.push_back({{x, y}, i});
        else Ee.push_back({{x, y}, i}); 
    }
   
    sort(Nn.begin(), Nn.end());
    sort(Ee.begin(), Ee.end(), [&](const pair<pi, int> & a , const pair<pi, int> & b) -> bool {
                return a.ff.ss < b.ff.ss;
            });
    
    for (auto N : Nn)
        for (auto E : Ee) {
            if (hit[E.ss].ff > N.xx && hit[N.ss].ff > E.yy) { 
                int xd = N.xx - E.xx,
                    yd = E.yy - N.yy;
                
                if (xd >= 0 && yd >= 0) {
                    if (xd == yd) continue;
                    if (xd > yd) hit[E.ss] = min(hit[E.ss], {N.xx, N.ss});
                    else hit[N.ss] = min(hit[N.ss], {E.yy, E.ss});
                }
            }
        }
    
    //cout << nl;
    //for (int i = 0; i < n; i++)
    //    cout << hit[i].ff << " " << hit[i].ss << nl << nl;

    for (int i = 0; i < n; i++) {
        int cur = hit[i].ss;
        while (cur != -1)
            ans[cur]++,
            cur = hit[cur].ss;
    }
    
    for (int i = 0; i < n; i++)
        cout << ans[i] << endl;
}
