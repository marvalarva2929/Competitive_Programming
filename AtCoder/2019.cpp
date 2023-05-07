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
    string s; cin >> s;
    int n = s.size();
    int diggies[n] = {};
    int mods[2019] = {};

    for (int i = 0; i < n; i++)
        diggies[i] = s[i] - '0';

    int a[n] = {}, // the total number (mod 2019) up to position i 
    b[n] = {};  // the total number scaled down by a factor 10^-i
    int inv = 202;
    mods[0]++;

    a[0] = diggies[0] % 2019,
    b[0] = a[0];

    for (int i = 1; i < n; i++) {
        a[i] = (((a[i - 1] * 10) % 2019) + diggies[i]) % 2019;
        b[i] = (a[i] * inv) % 2019;
        inv = ((inv * 202) % 2019);
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans += mods[b[i]];
        mods[b[i]]++;
    }
    cout << ans << nl;
}   

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t = 1;
    while (t--)
        solve();
}