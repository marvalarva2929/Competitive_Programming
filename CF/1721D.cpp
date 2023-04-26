using namespace std;
#include <bits/stdc++.h>
#define int long long
#define nl '\n'
#define no "no"
#define yes "yes"
#define print(x, y, z) for (int i = y; i <= z; i++) {cout << x[i] << " ";} cout << nl;

const int mxn = (int)1e5 + 10;
int a[mxn];
int b[mxn];

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
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];

    auto chk = [&n](const int x) -> bool {
        map<int, int> cnt;
        for (int i = 0; i < n; i++)
            cnt[(a[i]) & x]++,
            cnt[(~b[i]) & x]--;
        bool ans = true;
        for (auto p : cnt)  
            ans &= p.second == 0;
        return ans;
    };

    int ans = 0;
    for (int i = 29; i >= 0; i--) {
        if (chk(ans | (1 << i))) 
            ans |= (1 << i);
    }
    cout << ans << nl;

}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t; cin >> t;
    while (t--)
        solve();
}