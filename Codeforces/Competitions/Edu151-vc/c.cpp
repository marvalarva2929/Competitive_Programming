#include <bits/stdc++.h>
#define int long long
#define nl " \n"
#define pi pair<int, int>
#define ff first
#define ss second

using namespace std;

const int mxn = 3e5;
int a[mxn];
int l[10], r[10], occ[10];

void solve() {
    string s; cin >> s;
    int n = s.size();

    for (int i = 0; i < n; i++)
        a[i] = s[i] - '0';

    int m; cin >> m;
   
    for (int i = 0; i < m; i++) {
        char c; cin >> c;
        l[i] = c - '0';
    }
   
    for (int i = 0; i < m; i++) {
        char c; cin >> c;
        r[i] = c - '0';
    } 
    
    
    int idx = 0;
    int nm = 0;

    for (int i = 0; i < m && idx < n; i++) {
        int nmx = idx;
        set<int> all;
        for (int j = l[i]; j <= r[i]; j++)
            all.insert(j);
        
    

        while (idx < n) {
            all.erase(a[idx++]);
            if (all.size() == 0)
                break;
        }
   
        if (idx == n && (all.size() || i < m - 1)) {
            cout << "YES" << nl;
            return;
        } 
    }
    
    cout << "NO" << nl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t; cin >> t;
    while (t--)
        solve();
}
