#include <bits/stdc++.h>
#define int long long
#define nl " \n"
#define pi pair<int, int>
#define ff first
#define ss second

using namespace std;
const int mxn = (1 << 19);
int a[mxn+1], g[mxn + 1];
int n;

void dfs(int c) {
    if ((c<<1) > (2*n)) { g[c] = 1; return; }

    dfs(c<<1); dfs(c<<1|1);
    int l = g[c<<1], r = g[c<<1|1];
    
    g[c] = (a[c] != 0 ? l : 0) + (a[c] != 1 ? r : 0);
}

void fixt(int c) {
    while (c) {
        int l = g[c<<1], r = g[c<<1|1];
        g[c] = (a[c] != 0 ? l : 0) + (a[c] != 1 ? r : 0);
        c>>=1; 
    } 
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    cin >> n; n = (1 << n) - 1;
    string s; cin >> s;
    for (int i = 1; i <= n; i++)
        a[i] = (s[n - i] == '?' ? 2 : s[n - i] == '1' ? 1 : 0);

    fill(g + n, g + n + n, 1);
    
    dfs(1);

    int q; cin >> q;
    while (q--) {
        int x; char c; cin >> x >> c; x = n - x + 1;
        int b = (c == '?' ? 2 : (c == '1' ? 1 : 0));
        a[x] = b;
        
        fixt(x);
        cout << g[1] << nl;
    }
}
