#include <bits/stdc++.h>
#define int long long
#define nl " \n"
#define pi pair<int, int>
#define ff first
#define ss second

using namespace std;
template<class T> using V = vector<T>;
int n = 0;

struct SegTree {
    V<int> t;
    V<int> ar;

    SegTree(V<int> in) {
        ar = in; 
        t.resize(n * 4 + 1); 
        build();
    };


    void build(int v = 1, int l = 0, int r = n - 1) {
        if (l == r) t[v] = ar[l];
        else {
            int m = (l + r) >> 1;
            build(v * 2, l, m);
            build(v * 2 + 1, m + 1, r);
            t[v] = gcd(t[v * 2], t[v * 2 + 1]);
        }
    }

    int get(int l, int r, int v = 1, int tl = 0, int tr = n - 1) {
        if (l > r) return 0;
        if (l == tl && r == tr) return t[v];
        else {
            int m = (tl + tr) >> 1;
            if (v == -1) return 0;
            int left = get(l, min(r, m), v * 2, tl, m);
            int right = get(max(l, m + 1), r, v * 2 + 1, m + 1, tr);

            return gcd(left, right);
        }
    }
};

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    cin >> n;
    V<int> a(n);

    for (int i = 0; i < n; i++)
        cin >> a[i];

    SegTree seg(a);
    V<V<int>> segs(n);
    
    for (int i = 0; i < n; i++) {
        int l = i;
        int r = n - 1;
        int ans = i;

        while (l <= r) {
            int m = (l + r) >> 1; 
            if (seg.get(i, m) > (m - i + 1)) l = m + 1;
            else ans = m, r = m - 1;
        }
        
        if (seg.get(i, ans) == (ans - i + 1))
            segs[ans].push_back(i); 
    }
    

    int ans = 0;
    int p = -1;

    for (int i = 0; i < n; i++) {
        for (int x : segs[i])
            if (x > p) ans++, p = i;
        cout << ans << nl[i == n - 1]; 
    }
}

