using namespace std;
#include <bits/stdc++.h>
#define int long long
#define nl '\n'
#define mod 1000000007
#define MAX (int)1e5 + 10

int fact[MAX];

void solve() {
    int n; cin >> n;
    cout << (((n * (n - 1)) % mod) * (fact[n] % mod)) % mod << nl;

    // cout << fact[n] << nl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    fact[0] = 1;
    for (int i = 1; i < MAX; i++)
        fact[i] = ((i * fact[i - 1])) % mod;



    int t; cin >> t;
    while (t--)
        solve();
}