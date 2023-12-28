#include <bits/stdc++.h>
#define int long long
#define nl " \n"
#define pi pair<int, int>
#define ff first
#define ss second

using namespace std;

bool p2(int x) {
    while (x != 1) {
        if (x&1) return 0;
        x >>= 1;
    }
    return 1; 
}

int cnt(int x) {
    int c = 0;
    while (x) x >>= 1, c++;
    return c;
}

int solve() {
    int a, b; cin >> a >> b;
    a %= b;
    if (!a) return 0;
    
    int t = gcd(a, b);
    a /= t;
    b /= t;
    if (!p2(b)) return -1;

    int ans = 0, tb = b;

    while (a) {
        if (a & 1) ans += (b - 1) * (tb / b);
        a >>= 1;
        b >>= 1; 
    }
    return ans * t;
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t; cin >> t;
    while (t--)
        cout << solve() << nl;
}
