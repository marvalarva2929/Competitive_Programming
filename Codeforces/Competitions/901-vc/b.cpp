#include <bits/stdc++.h>
#define int long long
#define nl " \n"
#define pi pair<int, int>
#define ff first
#define ss second

using namespace std;
const int mxn = 100;
int a[mxn], b[mxn];

void solve() {
    int n, m, k; cin >> n >>m >> k;
    k--;
    
    int mn = 0, mx = 0; 

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] < a[mn]) mn = i; 
    }
    for (int i = 0; i < m; i++) {
        cin >> b[i];
        if (b[i] > b[mx]) mx = i; 
    }
    
    if (b[mx] > a[mn]) swap(a[mn], b[mx]);
    
    if (k&1) {
        int mn = 0, mx = 0; 
        for (int i = 0; i < n; i++) {
            if (a[i] > a[mx]) mx = i; 
        }
        for (int i = 0; i < m; i++) {
            if (b[i] < b[mn]) mn = i; 
        }
        if (a[mx] > b[mn]) swap(a[mx], b[mn]);
    }
    
    int s = 0;
    for (int i = 0; i < n; i++)
        s += a[i];

    cout << s << nl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t; cin >> t;
    while (t--)
        solve();
}
