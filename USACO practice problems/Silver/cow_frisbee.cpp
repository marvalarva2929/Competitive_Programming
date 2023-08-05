#include <bits/stdc++.h>
#define int long long
#define nl " \n"
#define pi pair<int, int>
#define ff first
#define ss second

using namespace std;
const int mxn = 3e5;
int occ[mxn + 1];
int a[mxn];

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int n; cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i], occ[a[i]] = i;

    set<int> locs;
    int ans = 0;

    for (int i = n; i; i--) {
        if (locs.size()) {
            int j = occ[i];
            auto bef = (locs.lower_bound(j)), af = locs.upper_bound(j);
            
            if (bef != locs.begin()) --bef;
            int b = *bef, a = *af;
    
            if (b < j) ans += j - b + 1;
            if (a > j) ans += a - j + 1;        
            
            //cout << i << " : " << j << " " << a << " " << b << nl;
        }     
        locs.insert(occ[i]);
    }

    cout << ans << endl;
}
