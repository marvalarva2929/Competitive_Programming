#include <bits/stdc++.h>
#define int long long
#define nl " \n"
#define pi pair<int, int>
#define ff first
#define ss second

using namespace std;
const int mxn = 3e5;
int a[mxn], pref[mxn];

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int n; cin >> n;
    set<int> nn;
    int mxs = 0;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        mxs += a[i]; 
        if (a[i] > 1) nn.insert(i);
        pref[i] = (i ? pref[i - 1] + a[i] : a[i]); 
    }
  
    int ans = 0;

    for (int i = 0; i < n; i++) {
        auto ibg = nn.upper_bound(i);
        int s = 0, p = a[i];
        while (ibg != nn.end()) {
            int r = *ibg;
            p *= a[r];
            s = pref[r] - (i ? pref[i - 1] : 0); 
            
            ans += p == s;
            ibg++;
            if (p > mxs) break;
        }
    }
    
    cout << ans << nl;
}
