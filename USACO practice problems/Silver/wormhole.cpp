using namespace std;
#include <bits/stdc++.h>
#define int long long
#define nl '\n'

const int mxn = (int)1e5 + 10;

int id[mxn];
int sz[mxn];
int a[mxn];
vector<pair<int, pair<int, int>>> wh; // weight, to, from
vector<pair<int, int>> fix;
int n, m;

int root(int x) {
    while (x != id[x]) {
        x = id[x];
        id[x] = id[id[x]];
    }
    return x;
}

void clear() {
    iota(id, id + n + 1, 0);
    fill(sz, sz + n + 1, 1);   
}

bool isct(int p, int q) {
    return root(p) == root(q);
}

void ct(int p, int q) {
    p = root(p);
    q = root(q);
    if (p == q) return;

    if (sz[p] < sz[q])
        swap(p, q);
    id[q] = p;
    sz[p] += sz[q];
}

bool check(int x) {
    clear();
    for (int i = x; i < wh.size(); i++)
        ct(wh[i].second.first, wh[i].second.second);
    for (int i = 0; i < n; i++)
        if (!isct(i + 1, a[i]))
            return false;
    return true;
}





signed main() {
    ifstream cin("wormsort.in");
    ofstream cout("wormsort.out");
    cin >> n >> m;
    clear();

    for (int i = 0; i < n; i++)
        cin >> a[i];

    bool ok = true;
    for (int i = 0; i < n; i++)
        ok &= (a[i] == i + 1);

    if (ok) {
        cout << -1 << nl;
        return 0;
    }

    for (int i = 0; i < m; i++) {
        int a, b, w; cin >> a >> b >> w;
        wh.push_back({w, {a, b}});
    }
    sort(wh.begin(), wh.end());

    int l = 0, r = m;
    while (r - l > 1) {
        int mid = (r + l)/2;
        if (check(mid))
            l = mid;
        else r = mid;
    }


    cout << wh[l].first  << nl;
}