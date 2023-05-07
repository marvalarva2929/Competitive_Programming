using namespace std;
#include <bits/stdc++.h>
#define int long long
#define nl '\n'
#define no "no"
#define yes "yes"
#define print(x, y, z) for (int i = y; i <= z; i++) {cout << x[i] << " ";} cout << nl;
#define pi pair<int, int>
#define ff first
#define ss second
#define max(x,y) (int)max((int)x, (int)y)
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

const int mxn = 2e5;
pi a[mxn];
int n;
string s;

void solve(int t) {
    cin >> n >> s;
    int moves = 0;
    int segs = 0;

    // if (t == 25) {
    //     cout << s << nl;
    // }

    for (int i = 0; i < n; i += 2)
        moves += s[i] != s[i + 1];
    
    char last = '-';
    for (int i = 0; i < n; i += 2) {
        if (s[i] == s[i + 1]) {
            if (s[i] != last) 
                segs++;
            last = s[i];
        }
    }

    cout << moves << " " << max(1, segs) << nl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t; cin >> t;
    for (int i = 1; i <= t; i++)
        solve(i);
}