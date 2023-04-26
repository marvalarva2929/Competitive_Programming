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

void solve() {
    int n; cin >> n;
    int a[n] = {};
    int cnt[2 * n] = {};
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int curr = 0;
    cnt[curr]++;
    int ans = (n * (n + 1))/2;
    for (int i = 0; i < n; i++) {
        curr ^= a[i];
        for (int j = 0; j * j < (2 * n); j++) 
            if ((curr ^ (j * j)) < (2 * n))
                ans -= cnt[curr ^ (j * j)];
        cnt[curr]++;
    }
    cout << ans << nl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t; cin >> t;
    while (t--)
        solve();
}