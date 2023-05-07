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

const int mxn = 30;
bool a[mxn];
bool b[mxn];

void solve() {
    int n, m; cin >> n >> m;
    for (int i = 0; i < n; i++) {
        char c; cin >> c;
        a[i] = c == 'R';
    }
    for (int i = 0; i < m; i++) {
        char c; cin >> c;
        b[i] = c == 'R';
    }
    reverse(b, b + m);
    for (int i = n; i < m + n; i++)
        a[i] = b[i - n];
    
    int fl = 0;
    for (; fl < n + m - 1; fl++)
        if (a[fl] == a[fl + 1]) break;
    
    int fr = n + m - 1;
    for (; fr > 0; fr--)
        if (a[fr] == a[fr - 1]) break;
    
    // cout << fr << " " << fl << nl;

    cout << (fr <= (fl + 1) ? yes : no) << nl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t; cin >> t;
    while (t--)
        solve();
}