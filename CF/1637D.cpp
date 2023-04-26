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

const int mxn = 100;
int a[mxn];
int b[mxn];
int n;

void solve() {
    cin >> n;
    int s = 0;
    for (int i = 0; i < n; i++)
        cin >> a[i],
        s += a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i],
        s += b[i];

    bitset<mxn * 100 + 1> possible_sums;
    possible_sums[a[0]] = 1;
    possible_sums[b[0]] = 1;

    for (int i = 1; i < n; i++) {
        bitset<mxn * 100 + 1> updated_sums;
        updated_sums |= (possible_sums << a[i]);
        updated_sums |= (possible_sums << b[i]);
        possible_sums = updated_sums;
    }    

    int ans = LLONG_MAX;

    for (int i = 0; i <= n * 100; i++)
        if (possible_sums[i])
            ans = min(ans, (i * i) + ((s - i) * (s - i)));

    for (int i = 0; i < n; i++)
        ans += (n - 2) * a[i] * a[i];
    for (int i = 0; i < n; i++)
        ans += (n - 2) * b[i] * b[i];

    cout << ans << nl;

}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t; cin >> t;
    while (t--)
        solve();
}