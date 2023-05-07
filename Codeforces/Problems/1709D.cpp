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

const int mxn = (int)2e5 + 10;
int a[mxn];

class SegmentTree {
    private:
    int *t;
    int N;

    void build(int v, int l, int r) {
        if (l == r) {
            t[v] = a[l];
        } else {
            int m = (l + r) >> 1;
            build(v * 2, l, m);
            build(v * 2 + 1, m + 1, r);
            t[v] = max(t[v * 2 + 1], t[v * 2]);
        }
    }

    int get(int v, int tl, int tr, int l, int r) {
        if (l > r)
            return 0;
        if (l == tl && r == tr)
            return t[v];
        int tm = (tl + tr) >> 1;

        int left = get(v * 2, tl, tm, l, min(r, tm));
        int right = get(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
        return max(left, right);
    }

    public:
    SegmentTree(int n) {
        this->N = n;
        this->t = new int[n * 4 + 1];
        build(1, 0, n - 1);
    }

    int getMax(int i, int j) {
        return get(1, 0, N - 1, i, j);
    }
};

void solve() {
    int n, m; cin >> n >> m;
    for (int i = 0; i < m; i++)
        cin >> a[i];
    int q; cin >> q;

    SegmentTree segs(m);

    for (int i = 0; i < q; i++) {
        int x1, y1, x2, y2, k; cin >> x1 >> y1 >> x2 >> y2 >> k;

        if ((abs(x2 - x1) % k) > 0 || (abs(y2 - y1) % k) > 0) {
            cout << no << nl;
            continue;
        }

        if (y2 < y1) {
            swap(x1, x2);
            swap(y1, y2);
        } 

        int thresh = segs.getMax(y1 - 1, y2 - 1);

        if (x1 > thresh) {
            cout << yes << nl;
            continue;
        }

        if ((k - ((thresh - x1 + 1) % k)) % k>= (n - thresh)) {
            cout << no << nl;
            continue;
        }
        cout << yes << nl;
    }
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t = 1;
    while (t--)
        solve();
}