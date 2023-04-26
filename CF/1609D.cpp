using namespace std;
#include <bits/stdc++.h>
#define int long long
#define nl '\n'
#define MAX (int)1e3 + 10
int id[MAX], sz[MAX];

int root(int i) {
    while (i != id[i]) {
        i = id[i];
        // id[i] = id[id[i]];
    }
    return i;
}

void ct(int p, int q) {
    p = root(p);
    q = root(q);
    if (p == q) return;
    if (sz[q] > sz[p]) swap(p, q);

    id[q] = p;
    sz[p] += sz[q];
}

void solve() {
    int n, m; cin >> n >> m;
    fill(sz, sz + n, 1);
    iota(id, id + n, 0);

    int ans[m] = {};
    int extra = 0;
    for (int i = 0; i < m; i++) {
        int x; int y; cin >> x >> y;
        --x, --y;
        if (root(x) == root(y)) extra++;
        else ct(x, y);
        vector<int> sizes;
        unordered_map<int, bool> seen;
        for (int j = 0; j < n; j++) {
            if (!seen[id[root(j)]])
            sizes.push_back(sz[root(j)]), 
            seen[id[root(j)]] = true;
        }
            
        sort(sizes.begin(), sizes.end(), greater<int>());
        for (int j = 0; j <= extra; j++)
            ans[i] += sizes[j];
        ans[i]--;
    }

    for (int i : ans)
        cout << i << nl;
    return;
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t = 1;
    while (t--)
        solve();
}