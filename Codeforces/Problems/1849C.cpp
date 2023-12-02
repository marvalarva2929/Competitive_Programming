#include <bits/stdc++.h>
#define int long long
#define nl " \n"
#define pi pair<int, int>
#define ff first
#define ss second

using namespace std;
const int mxn = 2e5;
bool a[mxn];
int gr[mxn], rg[mxn];

void solve() {
    int n, m; cin >> n >> m;
    fill(gr, gr + n, 0);
    fill(rg, rg + n, 0);

    for (int i = 0; i < n; i++) {
        char c; cin >> c;
        a[i] = c & 1;
    }
    
    int x = -1;
    for (int i = 0; i < n; i++) {
        if (!a[i]) x = i;
        gr[i] = x;
    }
    x = n;
    for (int i = n - 1; i >= 0; i--) {
        if (a[i]) x = i;
        rg[i] = x;
    }

    set<pi> st;
    for (int i = 0; i < m; i++) {
        int l, r; cin >> l >> r;
        
        int ll = rg[--l], rr = gr[--r];
        if (ll > rr) st.insert({-1, -1});
        else st.insert({ll, rr});
    }
    
    cout << st.size() << nl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);
    
    int t; cin >> t;
    while (t--)
        solve();
}
