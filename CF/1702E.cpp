using namespace std;
#include <bits/stdc++.h>
#define int long long
#define nl '\n'
#define MAX (int)2e5 + 10
#define pi pair<int, int>
#define f first
#define s second

int id[2 * MAX];
int sz[2 * MAX];

int root(int i) {
    while (i != id[i]) {
        i = id[i];
        id[i] = id[id[i]];
    }
    return i;
}

bool isct(int p, int q) {
    return root(p) == root(q);
}

void ct(int p, int q) {
    p = root(p);
    q = root(q);
    if (p == q) return;
    if (sz[q] > sz[p])
        swap(p, q);

    id[q] = id[p];
    sz[p] += sz[q];
}



void solve() {
    int n; cin >> n;
    iota(id, id + (n * 2) + 10, 0);
    fill(sz, sz + (n * 2) + 10, 1);
    unordered_map<int, int> cnt;
    vector<pi> pairs;
    pi p[n + 1] = {};

    for (int i = 0; i < n; i++) {
        int x, y; cin >> x >> y;
        cnt[x]++, cnt[y]++;
        pairs.push_back({x, y});
    }

    for (int i = 1; i <= n; i++) 
        if (cnt[i] != 2) {
            cout << "NO" << nl;
            return;
        }

    for (auto pair : pairs) {
        ct(pair.first, pair.second + n);
        ct(pair.first + n, pair.second);
    }

    for (int i = 1; i <= n; i++) 
        if (isct(i, i + n)) 
            { cout << "NO" << nl; return; }

    cout << "YES" << nl;
    return;
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t; cin >> t;
    while (t--)
        solve();
}