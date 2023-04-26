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
    if (n % 2) {    
        iota(a, a + n, n/2 + 1);
        a[0]--, a[n - 1]++, a[n - 2]++;
        for (int i : a)
            cout << i + 2 << " ";
        cout << nl;

    } else {
        // n /= 2;
        for (int i = 0; i < n; i++)
            cout << (n/2 + i >= n ? n/2 + i + 1 : n/2 + i)<< " ";
        cout << nl;
    }


    return;
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t; cin >> t;
    while (t--)
        solve();
    return 0;
}