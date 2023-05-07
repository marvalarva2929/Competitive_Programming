using namespace std;
#include <bits/stdc++.h>
#define int long long
#define nl '\n'
#define MAX (int)1e5 + 10
#define mod 998244353 
int id[MAX];
int v[MAX];
int e[MAX];
bool loop[MAX];

int root(int i) {
    while (i != id[i]) {
        i = id[i];
        id[i] = id[id[i]];
    }
    return i;
}

void ct(int p, int q) {
    p = root(p), q = root(q);
    if (p == q) return;
    if (v[p] < v[q])
        swap(p, q);
    
    id[q] = id[p];
    v[p] += v[q];
    e[p] += e[q];
    loop[p] |= loop[q];
}

void solve() {
    int n; cin >> n;
    fill(e, e + n + 1, 0);
    fill(v, v + n + 1, 1);
    fill(loop, loop + n + 1, 0);
    
    iota(id, id + n + 1, 0);

    int a[n] = {}, b[n] = {};

    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];
    
    for (int i = 0; i < n; i++) {
        ct(a[i], b[i]);
        e[root(a[i])]++;
        if (a[i] == b[i]) 
            loop[root(a[i])] = true;
    }

    // for (int i = 1; i <= n; i++)
    //     cout << i << " : "<< root(i) << " " << e[root(i)] << " " << v[root(i)] << nl;

    int ans = 1;
    int vis[n + 1] = {};
    for (int i = 1; i <= n; i++) 
        if (!vis[root(i)]) {
            if (v[root(i)] != e[root(i)]) ans = 0;
            else ans = (ans % mod) * ((loop[(root(i))] ? n : 2) % mod) % mod;
            vis[root(i)] = true; 
        }
    
    cout << ans << nl;
}


signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    int t; cin >> t;
    while (t--)
        solve();
}