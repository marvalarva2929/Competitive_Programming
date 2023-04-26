using namespace std;
#include <bits/stdc++.h>
#define int long long
#define nl '\n'
#define MAX (int)1e5 + 10

set<int> row[MAX], col[MAX];
bitset<MAX> atx, aty;

class Fenwick {
    private:

        int *Tree;
        int n;

    public:

    Fenwick(int N) {
        this->n = N;
        this->Tree = new int[this->n + 1];

        for (int i = 0; i <= this->n; i++)
            Tree[i] = 0;
    }

    void addValue(int key, int value) {
        int ix = key;
        while (ix <= n) {
            Tree[ix] += value;
            ix += (ix&-ix);
        }
    }

    int sumTo(int key) {
        int ix = key;
        int ret = 0;
        while (ix > 0) {
            // cout << ix << nl;
            ret += (Tree[ix]);
            ix -= (ix&-ix);
        }
        return ret;
    }

    int sumOfRange(int to, int from) {
        return sumTo(to) - sumTo(from);
    }

};

void solve() {
    int n, q; cin >> n >> q;
    Fenwick rx(n + 2);
    Fenwick ry(n + 2);


    for (int i = 0; i < q; i++) {
        int t; cin >> t;
        int x, y;
        switch (t) {
        case 1:
            cin >> x >> y;
            row[x].insert(y);
            col[y].insert(x);

            if (!atx[x]) rx.addValue(x, 1), atx[x] = 1;
            if (!aty[y]) ry.addValue(y, 1), aty[y] = 1;
            break;
        case 2:
            cin >> x >> y;
            row[x].erase(y);
            col[y].erase(x);

            if (!row[x].size()) rx.addValue(x, -1), atx[x] = 0;
            if (!col[y].size()) ry.addValue(y, -1), aty[y] = 0;
            break;
        case 3:
            // cin >> x >> y;
            // cout << "The sum to " << x << " is " << rx.sumTo(x) << " and the sum to " << y << " is " << ry.sumTo(y) << nl;
            // cout << "at" << rx.at(x) << nl;
            int x1, x2, y1, y2; cin >> x1 >> y1 >> x2 >> y2;
            if (rx.sumOfRange(x2, x1 - 1) == (x2 - x1 + 1) || ry.sumOfRange(y2, y1 - 1) == (y2 - y1 + 1)) 
                cout << "YES" << nl;
            else cout << "NO" << nl;
            break;
        default:
            break;
        }
    }
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t = 1;
    while (t--)
        solve();
}