#include <bits/stdc++.h>
#define int long long
#define nl " \n"
#define pi pair<int, int>
#define ff first
#define ss second

using namespace std;

const int mxn = 2e5;
const int MOD = 998244353;

int a[mxn], b[mxn], cnt[mxn + 1];
int tree[(mxn + 1) << 2];
int fact[mxn + 1];

int n, m;
int mx = 0;

int power(int a, int b) {
    int ans = 1;
    while (b) {
        if (b&1)
            ans = ans * a % MOD;
        b >>= 1;
        a = a * a % MOD;
    }
    return ans % MOD;
}

int inv(int x) {
    return power(x, MOD - 2) % MOD;
}

void build(int v = 1, int l = 1, int r = mx) {
    if (l == r)
        tree[v] = cnt[l];
    else {
        int m = (l + r) >> 1;
        build(v * 2, l, m);
        build(v * 2 + 1, m + 1, r);
        tree[v] = tree[v * 2] + tree[v * 2 + 1];
    }
}

int sum(int l, int r, int v = 1, int tl = 1, int tr = mx) {
    if (l > r) return 0;
    if (l == tl && r == tr) return tree[v];
    int tm = (tl + tr) >> 1;
    return sum(l, min(tm, r), v * 2, tl, tm) +
            sum(max(tm + 1, l), r, v * 2 + 1, tm + 1, tr);
}

void update(int i, int k, int v = 1, int tl = 1, int tr = mx) { 
    if (tl == tr)
        tree[v] = k;
    else {
        int tm = (tl + tr) >> 1;
        if (i <= tm)
            update(i, k, v * 2, tl, tm);
        else update(i, k, v * 2 + 1, tm + 1, tr);
        tree[v] = tree[v * 2] + tree[v * 2 + 1]; 
    }
}

void solve() {
    cin >> n >> m; 
    set<int> al;
    
    for (int i = 0; i < n; i++)
        cin >> a[i], cnt[a[i]]++, mx = max(mx, a[i]),
        al.insert(a[i]);
    for (int i = 0; i < m; i++)
        cin >> b[i];
    
    build();

    fact[0] = 1;
    for (int i = 1; i <= n; i++)
        fact[i] = fact[i - 1] * i % MOD,
        fact[i] %= MOD;
    
    int cur = 1;
    for (int x : al)
        cur = cur * fact[cnt[x]] % MOD;
    cur %= MOD;
    
    int ans = 0;

    for (int i = 0; i < min(n, m); i++) {
        ans = ans % MOD + (sum(1, b[i] - 1) % MOD * fact[n - i - 1] % MOD * inv(cur) % MOD);   
        ans %= MOD;

        cur = cur * inv(cnt[b[i]]) % MOD; 
        update(b[i], --cnt[b[i]]);
        if (cnt[b[i]] < 0) break;
        if (i == min(n, m) - 1 && n < m) 
            ans++;  
    } 
    
    cout << ans % MOD << nl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);
    
    int t = 1; 
    while (t--)
        solve();
}
