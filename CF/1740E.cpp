using namespace std;
#include <bits/stdc++.h>
#define int long long
#define nl '\n'
#define no "no"
#define yes "yes"
// #define print(x, y, z) for (int i = y; i <= z; i++) {cout << x[i] << " ";} cout << nl;

const int mxn = (int)1e6 + 10;
int par[mxn];
vector<int> adj[mxn];
int dp[mxn];
int dep[mxn];

void dfs(int x, int p, int depth) {
    for (int n : adj[x])
        if (n != p)
            (dfs(n, x, depth + 1));

    int add = dep[x];

    int maxC = 0;
    for (int n : adj[x])
        if (n != p)    
            maxC += (dp[n]);


    dp[x] = max(maxC, add);

    // cout << x << " " << dp[x] << " " << maxC << " " << add << nl;
}

int dfsl(int y, int p, int depth) {
    int ret = depth;
    for (int i : adj[y])
        if (i != p)
            ret = max(ret, dfsl(i, y, depth + 1));
    // ret -= depth;

    dep[y] = ret - depth + 1;
    // cout << y << " : " << dep[y] - depth << nl;
    return ret;
}

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

void solve() {
    int n; cin >> n;
    for (int i = 2; i <= n; i++) {
        int x; cin >> x;
        par[i] = x;
        adj[x].push_back(i);
    }

    dfsl(1, 0, 0);


    dfs(1, 0, 0);
    cout << dp[1] << nl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t = 1;
    while (t--)
        solve();
}