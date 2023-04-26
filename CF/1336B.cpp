using namespace std;
#include <bits/stdc++.h>
#include <string.h>
typedef long long ll;
typedef vector<int> vi;
typedef vector<pair<int,int>> vpi;
#define pb push_back
#define int long long
#define nl '\n'
#define rsz resize
#define sz(x) int(x.size())
#define all(x) begin(x), end(x)
#define no "no"
#define yes "yes"
#define print(x, y, z) for (int i = y; i <= z; i++) {cout << x[i] << " ";} cout << nl;
#define MAX (int)1e5 + 10
#define min(x, y) (long long)min((long long)x, (long long)y)
int ans = LONG_LONG_MAX;

int sq(int a) {
    return 1ll * a * a;
}

void solvergb(vector<int> a, vector<int> b, vector<int> c) {
    for (int i = 0; i < b.size(); i++) {
        auto ada = lower_bound(a.begin(), a.end(), b[i]);
        auto cua = upper_bound(c.begin(), c.end(), b[i]);
        int ad, cu; 

        if (ada == a.end() || cua == c.begin()) continue;

        cua--;
        ad = *ada;
        cu = *cua;

        int ab = sq(ad - b[i]), bc = sq(cu - b[i]), ac = sq(ad - cu);
        ans = min(ans, ab + bc + ac);
    }
}

void solve() {
    int nr, ng, nb; cin >> nr >> ng >> nb;

    vector<int> r(nr, INT_MAX);
    vector<int> g(ng, INT_MAX);
    vector<int> b(nb, INT_MAX);

    for (int i = 0; i < nr; i++) 
        cin >> r[i];
    for (int i = 0; i < ng; i++) 
        cin >> g[i];
    for (int i = 0; i < nb; i++) 
        cin >> b[i];
    

    sort(r.begin(), r.end());
    sort(g.begin(), g.end());
    sort(b.begin(), b.end());
    
    solvergb(r, g, b);
    solvergb(g, r, b);
    solvergb(b, g, r);
    solvergb(r, b, g);
    solvergb(g, b, r);
    solvergb(b, r, g);

    cout << ans << nl;
    ans = LONG_LONG_MAX;
}

int32_t main() {
    int t; cin >> t;
    while (t--)
        solve();
} 