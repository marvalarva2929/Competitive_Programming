#include <bits/stdc++.h>
#define int long long
#define nl " \n"
#define pi pair<int, int>
#define ff first
#define ss second

using namespace std;
const int mxn = 2e5, MOD = 998244353;
int a[mxn+1], fact[mxn + 1];

void solve() {
    string s; int n; cin >> s; n = s.size();
    for (int i = 0; i < n; i++)
        a[i] = s[i] & 1;
    a[n] = -1;

    int o = 0, w = 1;
    int cnt = 1;
    
    for (int i = 1; i <= n; i++)
        if (a[i] != a[i - 1]) {
            o += cnt-1;
            w = w * cnt % MOD;
            cnt = 1;
        } else cnt++; 
    
    w = w * fact[o] % MOD;

    cout << o << " " << w << nl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);
    
    fact[0] = 1;
    for (int i = 1; i <= mxn; i++)
        fact[i] = i * fact[i - 1] % MOD;

    int t; cin >> t;
    while (t--)
        solve();
}

