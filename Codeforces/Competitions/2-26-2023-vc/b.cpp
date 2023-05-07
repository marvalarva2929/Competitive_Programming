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

const int mxn = 60;
int a[mxn];

void add(int l, int r) {
    for (int i = l; i <= r; i++)
        a[i]++;
}

void solve() {
    int n, k; cin >> n >> k;
    memset(a, 0, sizeof a);

    for (int i = 0; i < n; i++) {
        int l, r; cin >> l >> r;
        if (l <= k && r >= k)
            add(l, r);
    }

    for (int i = 0; i < mxn; i++) {
        if (i != k && a[i] >= a[k]) {
            cout << no << nl;
            return;
        }
    }
    cout << yes << nl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t; cin >> t;
    while (t--)
        solve();
}