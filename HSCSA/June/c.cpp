#include <bits/stdc++.h>
#define int long long
#define nl " \n"
#define pi pair<int, int>
#define ff first
#define ss second

using namespace std;

signed main() {
    int n; cin >> n;
    
    int mx = INT_MIN, mn = INT_MAX,cnt = 0;
    int is = -1; 
    set<int> nots;

    for (int i = 0; i < n; i++) {
        string x; int y; cin >> x >> y;

        if (x == ">") mx = max(mx, y + 1);
        else if (x == ">=") mx = max(mx, y);
        else if (x == "<") mn = min(mn, y - 1);
        else if (x == "<=") mn = min(mn, y);
        else if (x == "!=") nots.insert(y);
        else if (x == "==") { cnt++; is = y; }; 
    }
    
    if (cnt == 1) {
        if (nots.count(is) == 1) cout << 0 << nl;
        else if (is > mn || is < mx) cout << 0 << nl;
        else cout << 1 << nl;
        return 0;
    } else if (cnt > 1) {
        cout << 0 << nl;
        return 0; 
    }
    
    if (mx > mn) {
        cout << 0 << nl;
        return 0; 
    }
    
    int ans = mn - mx + 1;
        
    for (int x : nots) {
        if (x >= mx && x <= mn)
            ans--; 
    }
    
    cout << ans << nl;
}
