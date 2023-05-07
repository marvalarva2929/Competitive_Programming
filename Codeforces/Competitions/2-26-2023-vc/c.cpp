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

const int mxn = 2e5 + 10;
int a[mxn];
int b[mxn];
int c[mxn];
int mul[mxn];
int ans[mxn];

void solve() {
    int n; cin >> n;
    fill(ans, ans + n + 1, 0);
    fill(mul, mul + n + 1, 0);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i],
        c[i + 1] = b[i];
    
    for (int i = 1; i <= n; i++)
        c[i] += c[i - 1];
    
    for (int i = 0; i < n; i++) {
        int l = i - 1, r = n + 1;
        while (r - l > 1) {
            int m = (r + l) >> 1;
            if (c[m] - c[i] <= a[i])
                l = m;
            else r = m;
        }
        int left = a[i] - (c[l] - c[i]);
        if (l < n)
            ans[l] += left;
        mul[i]++;
        mul[l]--;
        // cout << i << " " << l << nl;
    }
    for (int i = 1; i < n; i++)
        mul[i] += mul[i - 1];

    for (int i = 0; i < n; i++)
        cout << (ans[i] + (b[i] * mul[i])) << " ";
    cout << nl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t; cin >> t;
    while (t--)
        solve();
}