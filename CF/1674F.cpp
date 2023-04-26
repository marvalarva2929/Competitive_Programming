using namespace std;
#include <bits/stdc++.h>
#define int long long
#define nl '\n'
#define no "no"
#define yes "yes"
#define print(x, y, z) for (int i = y; i <= z; i++) {cout << x[i] << " ";} cout << nl;

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

const int mxn = 1e6;
int a[mxn];
int n, m, q;
int _n;

class SegmentTree {
    private:
    int *t;

    void build(int v, int l, int r) {
        if (l == r) {
            t[v] = a[l];
            return;
        }        
        int m = (l + r) >> 1;
        build(v * 2, l, m);
        build(v * 2 + 1, m + 1, r);
        t[v] = t[v * 2] + t[v * 2 + 1];
    }

    int get(int v, int tl, int tr, int l, int r) {
        if (l > r) return 0;
        if (tl == l && tr == r)
            return t[v];
        int tm = (tl + tr) >> 1;
        return get(v * 2, tl, tm, l, min(r, tm)) + 
                get(v * 2 + 1, tm + 1, tr, max(tm + 1, l), r);
    }

    void update(int idx, int k, int v, int tl, int tr) {
        if (tl == tr) {
            t[idx] = v;
        } else {   
            int tm = (tr + tl) >> 1;
            if (k <= tm)
                update(idx * 2, k, v, tl, tm);
            else update(idx * 2 + 1, k, v, tm + 1, tr);
            t[idx] = t[idx * 2] + t[idx * 2 + 1];
        }
    }

    public:

    SegmentTree() {
        t = new int[_n*4 + 1];
        fill(t, t + (_n*4 + 1), 0);
        build(1, 0, _n - 1);
    }

    int getSum(int i, int j) {
        return get(1, 0, _n - 1, i, j);
    }

    void change(int k, int v) {
        update(1, k, v, 0, _n - 1);
    }
};

void solve() {
    cin >> n >> m >> q;
    _n = n * m; 
    int cur = 0;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            char x; cin >> x;
            cur += x == '*';
            a[i + (j * n)] = (x == '*');
        }

    SegmentTree segs;

    // for (int i = 0; i < _n; i++)
    //     cout << a[i] << " ";
    // cout << nl;

    while (q--) {
        int x, y; cin >> x >> y;
        --x, --y;
        int idx = (x) + (y * n);
        cur += !a[idx];
        cur -= a[idx];
        a[idx] = !a[idx];
        segs.change(idx, a[idx]);
        cout << cur - segs.getSum(0, cur-1) << nl;
    }
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t = 1;
    while (t--)
        solve();
}