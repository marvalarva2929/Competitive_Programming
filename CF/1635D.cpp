using namespace std;
#include <bits/stdc++.h>
#define int long long
#define nl '\n'
#define no "no"
#define yes "yes"
#define print(x, y, z) for (int i = y; i <= z; i++) {cout << x[i] << " ";} cout << nl;
#define mod ((int)1e9 + 7)

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

const int mxn = 2e5;
int dp[mxn + 1];
int n, p;
int ans = 0;

void solve() {
    vector<int> a;
    unordered_map<int, int, custom_hash> cnt;
    set<int> ua;
    cin >> n >> p;

    for (int i = 0; i < n; i++)
        { int x; cin >> x; a.push_back(x); cnt[x] = true; }

    sort(a.begin(), a.end(), greater<int>());

    for (int x : a) {
        int tmp = x;
        while (x > 0) {
            if (x & 1)  
                x >>= 1;
            else if (x & 3)
                break;
            else x >>= 2;

            if (cnt[x])
                break;
        }
        if (!cnt[x] || x == tmp)
            ua.insert(tmp);
    }

    for (int x : ua)
        dp[__lg(x)]++;
    
    dp[1] += dp[0];
    for (int i = 2; i < p; i++)
        dp[i] = (dp[i] + dp[i - 1] + dp[i - 2] + mod) % mod;
    
    for (int i = 0; i < p; i++)
        ans = (ans + dp[i]) % mod;
    
    cout << ans % mod << nl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    // int t; cin >> t;
    // while (t--)
        solve();
}