using namespace std;
#include <bits/stdc++.h>
#define int long long
#define nl '\n'
#define no "no"
#define yes "yes"
#define print(x, y, z) for (int i = y; i <= z; i++) {cout << x[i] << " ";} cout << nl;
#define pi pair<int, int> 
#define mod 998244353

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

int power(int a, int b) {
    int ans = 1;
    while (b) {
        if (b & 1)  
            ans = (ans * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return ans % mod;
}

int inv(int a) {
    return power(a, mod - 2);
}

int mul(int a, int b) { 
    return ((a % mod) * (b % mod)) % mod;
}

int divide(int a, int b) {
    return a * inv(b);
}


void solve() {
    int n; cin >> n;
    int ans = 1;
    for (int i = 1; i <= n/6; i++)
        ans = mul(ans, divide(n/6 + i, i));

    for (int i = 1; i <= n; i += 3) {
        int a, b, c; cin >> a >> b >> c;
        int cc[3] = {a, b, c};
        int mx = 0;
        int cnt = 0;
        for (int i = 0; i < 3; i++)
            for (int j = i + 1; j < 3; j++)
                mx = max(mx, cc[i] + cc[j]);
        for (int i = 0; i < 3; i++)
            for (int j = i + 1; j < 3; j++)
                cnt += (cc[i] + cc[j] == mx);
        // cout << i << " " << cnt << nl;
        ans = (ans * cnt) % mod;
    }
    cout << ans % mod << nl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);
    int t = 1;

    while (t--)
        solve();
}