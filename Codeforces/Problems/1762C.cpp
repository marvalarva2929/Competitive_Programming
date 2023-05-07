using namespace std;
#include <bits/stdc++.h>
#define int long long
#define nl '\n'
#define MAX (int)2e5 + 10
#define mod 998244353 
int suff[MAX];

int power(int a, int b) {
    int ans = 1;
    while (b > 0) {
        if (b & 1)
            ans = (ans % mod) * (a % mod) % mod;
        a = (a % mod) * (1ll * (a % mod)) % mod;
        b >>= 1;
    }
    return ans % mod;
}

void solve() {
    int n; string s; cin >> n >> s;
    fill(suff, suff + n + 1, 0);
    suff[0] = 1;
    for (int i = 1; i < n; i++)
        suff[i] = (s[i] == s[i - 1] ? suff[i - 1] + 1 : 1);

    int ans = 0;    
    for (int i = 1; i <= n; i++)
        ans += (power(2, suff[i - 1] - 1)) % mod;
    cout << ans % mod << nl;
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    int t; cin >> t;
    while (t--)
        solve();
}