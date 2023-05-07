using namespace std;
#include <bits/stdc++.h>
#define int long long
#define nl '\n'
#define no "no"
#define yes "yes"
#define print(x, y, z) for (int i = y; i <= z; i++) {cout << x[i] << " ";} cout << nl;
int lastD = -1;

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

bool check(set<int> digs, int l, int r, bool carry) {
    for (int i = l; i <= r; i++)
        if (carry && i == lastD)
            continue;
        else if (!digs.count(i)) { return false; }
    return true;    
}

void solve() {
    int n, p; cin >> n >> p;
    int a[n + 1] = {};
    set<int> all;

    for (int i = 1; i <= n; i++)
        cin >> a[i], all.insert(a[i]);

    if (all.size() == p) {
        cout << 0 << nl;
        return;
    }

    lastD = -1;

    for (int i = n - 1; i >= 0; i--)
        if (a[i] < p - 1)
            { lastD = a[i] + 1; break; }

    int l = 0, r = p - 1;
    int x = a[n];

    while (r > l) {
        int m = (l + r) >> 1    ;
        bool work = false;
        if (x + m >= p) {
            if (check(all, x + m - p + 1, x - 1, true)) 
                work = true;
            else work = false;
        } else {
            if (check(all, 0, x - 1, false) && check(all, x + m + 1, p - 1, false))
                work = true;
            else work = false;
        }
        if (work)
            r = m;
        else l = m + 1;
    }

    cout << l << nl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t; cin >> t;
    while (t--)
        solve();
}