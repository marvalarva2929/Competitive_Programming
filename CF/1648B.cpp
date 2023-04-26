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

const int mxn = 1e6;
int cnt[mxn+1];
set<int> a;

void solve() {
    int n, c; cin >> n >> c;
    a.clear();
    fill(cnt, cnt + c + 1, 0);
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        a.insert(x);
    }
    for (int y : a) {
        cnt[y]++;
    }

    for (int i = 1; i <= c; i++)
        cnt[i] += cnt[i - 1];
    
    for (int y : a) {
        for (int x = 1; x <= c/y; x++) {
            if (!a.count(x)) {
                if (cnt[min(c, (y * (x + 1)) - 1)] - cnt[(y * x) - 1] > 0) {
                    // cout << y << " " << x << nl;
                    cout << "NO" << nl;
                    return;
                }
            }
        }
    }
    cout << "YES" << nl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t; cin >> t;
    while (t--)
        solve();
}