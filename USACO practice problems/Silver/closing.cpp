using namespace std;
#include <bits/stdc++.h>
#define int long long
#define nl '\n'
#define pi pair<int, int>
#define f first
#define s second

const int mxn = (int)3e3 + 10;
set<int> exists;
vector<pi> roads;
int n, m; 

class DSU {
    private:

    int id[mxn];
    int sz[mxn];

    int root(int x) {
        while (x != id[x]) {
            id[x] = id[id[x]];
            x = id[x];
        }
        return x;
    }

    public: 

    DSU() {
        iota(id, id + n + 1, 0);
        fill(sz, sz + n + 1, 1);
    }

    void ct(int p, int q) {
        p = root(p);
        q = root(q);
        if (p == q)
            return;

        if (sz[q] > sz[p])
            swap(p, q);
        
        id[q] = p;
        sz[p] += sz[q];
    }

    bool isct(int p, int q) {
        return root(p) == root(q);
    }

    bool isConnected() {
        for (auto road : roads)
            if (exists.count(road.f) && exists.count(road.s))
                ct(road.f, road.s);
        int last = 0;
        for (int barn : exists) {
            if (last == 0)
                last = barn;
            else if (!isct(barn, last))
                return false;
        }
        return true;
    }

};

signed main() {
    ifstream cin("closing.in");
    ofstream cout("closing.out");
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int to, from; cin >> to >> from;
        roads.push_back({to, from});
    }
    for (int i = 1; i <= n; i++)
        exists.insert(i);

    for (int i = 0; i < n; i++) {
        DSU dsu;
        cout << (dsu.isConnected() ? "YES" : "NO") << nl;
        int next; cin >> next;
        exists.erase(next);
    }
}