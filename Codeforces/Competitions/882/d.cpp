#include <bits/stdc++.h>
#define int long long
#define nl " \n"
#define pi pair<int, int>
#define ff first
#define ss second

using namespace std;
const int mxn = 2e5;
int a[mxn], e[mxn];
pi segs[mxn];
int n, m, q;

struct SegTree {
    vector<int> t;
    int n;
    SegTree(vector<int> arr) {
        n = arr.size();
        t.resize(2*n);
        for (int i = 0; i < n; i++) t[n+i] = arr[i];
        build();
    }
    int f(int a, int b) {
        return a+b;
    }
    void build() {  // build the tree
        //original array is 0 indexed, seg is 1 indexed
        for (int i = n - 1; i > 0; --i) t[i] = f(t[i<<1], t[i<<1|1]);
    }
    void modify(int p, int value) {  // set value at position p
        for (t[p += n] = value; p > 1; p >>= 1) t[p>>1] = f(t[p], t[p^1]);
    }
    void update(int p, int value) {  // update value at position p
        for (t[p += n] += value; p > 1; p >>= 1) t[p>>1] = f(t[p], t[p^1]);
    }
    int query(int l, int r) {  // sum on interval [l, r)
        int res = 0; //CAREFUL IF MIN/MAX/GCD
        for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if (l&1) res = f(res, t[l++]);
            if (r&1) res = f(res, t[--r]);
        }
        return res;
    }
};


void solve() {
    cin >> n >> m >> q;

    string s; cin >> s;
    for (int i = 0; i < n; i++)
        a[i] = s[i] & 1;

    for (int i = 0; i < m; i++)
        cin >> segs[i].ff >> segs[i].ss, segs[i].ff--, segs[i].ss--;


    set<int> all;
    for (int i = 0; i < n; i++)
        all.insert(i);
    int cnt = 0;
    fill(e, e + n, -1); 
    
    for (int i = 0; i < m; i++) {
        auto it1 = all.lower_bound(segs[i].ff);
        
        while (it1 != all.end() && *it1 <= segs[i].ss)
            e[*it1] = cnt++,
            all.erase(it1++);
    } 


    if (cnt > n) { cout << "urmom" << nl; return;} ;

    vector<int> d(n, 1);

    for (int i = 0; i < n; i++)
        if (e[i] != -1)
            d[e[i]] = !a[i];
    
    SegTree seg(d);

    int one = 0;
    for (int i = 0; i < n; i++)
        one += a[i];
    
   // for (int i = 0; i < n; i++)
   //     cout << d[i] << nl[i == n - 1];

   // cout << seg.query(0, ) << nl;

    while (q--) {
        int x; cin >> x; --x;
        if (a[x]) one--;
        else one++;

        a[x] ^= 1;
        if (e[x] != -1) seg.modify(e[x], !a[x]);
    

        cout << seg.query(0, min(cnt, one)) << nl;
    }
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);
    
    int t = 1;
    while (t--)
        solve();
}
