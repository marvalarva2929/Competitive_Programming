#include <bits/stdc++.h>
#define int long long
#define nl " \n"
#define pi pair<int, int>
#define ff first
#define ss second

using namespace std;
const int MOD = 998244353;
const int mxn = 1e6;
int a[mxn + 1];

int power(int a, int b) {
    a %= MOD;
    int ans = 1;

    while (b) {
        if (b&1) ans = ans * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    
    return ans;
}

int inv(int x) { return power(x, MOD - 2) % MOD; }

void solve() {
    int n; cin >> n;
    int diff = 0;
    string s;

    for (int i = 0; i < n; i++) {
        char c; cin >> c;
        s.push_back(c);
    }

    for (int i = 0; i < n; i++) {
        char c; cin >> c;
        diff += s[i] != c;
    }

    a[n] = 1;
    for (int i = n - 1; i > 0; i--) {
        a[i] = (((n - i) * a[i + 1] % MOD) + n) * inv(i) % MOD; 
    }
    
    int ans = 0;
    for (int i = 1; i <= diff; i++)
        ans = (ans + a[i]) % MOD;

    cout << ans % MOD << nl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);
    
    int t; cin >> t;
    while (t--)
        solve();
}
