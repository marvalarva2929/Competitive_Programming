using namespace std;
#include <bits/stdc++.h>
#define int long long
#define nl '\n'
#define no "no"
#define yes "yes"
#define print(x, y, z) for (int i = y; i <= z; i++) {cout << x[i] << " ";} cout << nl;
#define pi pair<int, int>
#define f first
#define s second

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

const int mxn = 60;
const int mxm = 2000;
vector<int> adj[mxn];
pi a[mxm];


void solve() {
    int n, m; cin >> n >> m;
    fill(adj, adj + n + 1, vector<int>());
    for (int i = 0; i < m; i++) {
        int p, q; cin >> p >> q;
        if (q < p)
            swap(p, q);
        a[i] = {p, q};
        adj[p].push_back(q);
        adj[q].push_back(p);
    }

    bool isclique = true;
    for (int i = 1; i <= n; i++)
        isclique &= adj[i].size() == (n - 1);

    if (isclique) {
        cout << 3 << nl;
        for (int i = 0; i < m; i++) {
            if (a[i].f == 1) {
                if (a[i].s == 3)
                    cout << 3 << " ";
                else cout << 1 << " ";
            } else if (a[i].f == 2) {
                cout << 2 << " ";
            } else if (a[i].f == 3 || a[i].s == 3) {
                cout << 3 << " ";
            } else {
                if (a[i].f != 3 && a[i].s != 3)
                    cout << 1 << " ";
                else if (a[i].f != 2 && a[i].s != 2)
                    cout << 3 << " ";
                else if (a[i].f != 1 && a[i].s != 1)
                    cout << 2 << " ";
            }
        }
    } else {
        int leaf = 0;
        cout << 2 << nl;
        for (int i = 1; i <= n; i++)
            if (adj[i].size() != (n - 1)) 
                { leaf = i; break; }
        for (int i = 0; i < m; i++)
            if (a[i].first == leaf || a[i].second == leaf)
                cout << 2 << " ";
            else cout << 1 << " ";
        cout << nl;
    }
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t; cin >> t;
    while (t--)
        solve();
}