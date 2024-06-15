#include <bits/stdc++.h>
#define int long long
#define nl endl
#define pi pair<int, int>
#define ff first
#define ss second

using namespace std;
const int mxn = 3e5;
int a[mxn], b[mxn], d[mxn];
int mx[mxn];

void solve() {
    int n, q, c; cin >> n >> q >> c;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    fill(b, b + n, INT_MAX);
    fill(d, d + n, 0);

    for (int i = 0; i < q; i++) {
        int a, h; cin >> a >> h; --h;
        b[h] = min(b[h], a); 
    }
    
    vector<pi> seggs;

    for (int i = 0; i < n; i++) {
        if (b[i] != INT_MAX) {
            seggs.push_back({b[i], i});
        }
    } 
    
    for (auto [f, s] : seggs) {
        if (d[s] == 1) {
            cout << -1 << endl;
            return;
        } 
        d[s] = -1; 
        for (int i = f; i < s; i++) {
            if (d[i] == -1) {
                cout << -1 << endl;
                return;
            } 
            d[i] = 1;
        }
    }
    
    vector<int> mx(n);
        
    //int m = 0;
    //for (int i = 0; i < n; i++) {
    //    if (d[i] == -1 && a[i] == 0) {
    //        a[i] = m + 1;
    //    } else if (d[i] == -1 && a[i] <= m) {
    //        cout << -1 << nl;
    //        return;
    //    }
    //    m = max(a[i], m);
    //    mx[i] = m; 
    //}
    
    
    

    int ls = -1;
    //for (int i = 0; i < n; i++)
    //    cout << d[i] << nl[i == n -1];
    
    int m = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] > m && d[i] == 1) { // max changes when it should not
            if (ls == -1) {
                cout << -1 << nl;
                return;
            } else a[ls] = a[i]; // stop max from changing
        } else if (a[i] == 0 && d[i] == 1) a[i] = 1;
        
        if (d[i] == 0 && a[i] == 0) ls = i, a[i] = 1; // the last place where the max can be changed
        if (d[i] == -1) {
            if (a[i] == 0) ls = i, a[i] = m + 1; 
            else if (a[i] <= m) { cout << -1 << nl; return; }
            else ls = -1;
        }
            
        //cout << i << " : " << d[i] << " " << ls << nl;

        m = max(m, a[i]);
    }
    
    if (m > c) {
        cout << -1 << endl;
        return;
    }
    
    cout << a[0];
    for (int i = 1; i < n; i++)
        cout << " " <<  a[i];
    cout << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t; cin >> t;
    while (t--)
        solve();
}
