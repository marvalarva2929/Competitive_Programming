using namespace std;
#include <bits/stdc++.h>
#define int long long
#define nl '\n'

class SegmentTree {

    private:
    int n;
    int *t;
    vector<int> m;

    void build(int v, int tl, int tr) {
        if (tl == tr)
            t[v] = m[tl];
        else {
            int tm = (tl + tr) >> 1;
            build(v * 2, tl, tm);
            build(v * 2 + 1, tm + 1, tr);
            t[v] = t[v * 2] + t[v * 2 + 1];
        }
    }

    void update(int v, int pos, int new_val, int tl, int tr) {
        if (tl == tr)
            t[v] = new_val;
        else {
            int tm = (tl + tr) >> 1;
            if (pos <= tm) update(v * 2, pos, new_val, tl, tm);
            else update(v * 2 + 1, pos, new_val, tm + 1, tr);
            t[v] = t[v * 2] + t[v * 2 + 1];
        }
    }

    int sum(int v, int l, int r, int tl, int tr) {
        if (l > r)
            return 0;
        if (tl == l && tr == r)
            return t[v];
        
        int tm = (tl + tr) >> 1;
        return sum(v * 2, l, min(r, tm), tl, tm) + 
                sum(v * 2 + 1, max(l, tm + 1), r, tm + 1, tr);          
    }

    public:

    SegmentTree(int in, vector<int> a) {
        n = in;
        this->m = a;
        this->t = new int[in * 4 + 1];
        build(1, 0, in - 1);
    }

    int getSumOf(int i, int j) {
        return sum(1, i, j, 0, n - 1);
    }

    void change(int key, int val) {
        update(1, key, val, 0, n - 1);
    }
};

signed main() {
    // cin.tie(0)->sync_with_stdio(false);

    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    SegmentTree seg(n, a);

    while (true) {
        char c;
        int x, y; cin >> c >> x >> y;
        if (c == 'u')
            seg.change(x, y);
        else cout << seg.getSumOf(x, y) << nl;
    }
}