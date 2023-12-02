#include <bits/stdc++.h>
#define int long long
#define nl " \n"
#define pi pair<int, int>
#define ff first
#define ss second

using namespace std;
const int mxn = 1e6, MOD = 1e9 + 7;
int fact[mxn + 1], inf[mxn + 1];

int power(int a, int b) {
    int ans = 1;
    a %= MOD;
    while (b) {
        if (b & 1) ans = a * ans % MOD;
        b >>= 1;
        a = a * a % MOD;
    }
    return ans % MOD;
}

int inv(int x) { return power(x, MOD - 2) % MOD; }

int choose(int n, int k) {
    return fact[n] * inf[k] % MOD * inf[n - k] % MOD;
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    fact[0] = 1;
    for (int i = 1; i <= 1e6; i++)
        fact[i] = fact[i - 1] * i % MOD;
   
    inf[(int)1e6] = inv((fact[(int)1e6])); 
    for (int i = 1e6 - 1; i >= 0; i--)
        inf[i] = inf[i + 1] * (i + 1) % MOD;
    
    int n, k; cin >> n >> k;
    int cnt = 0;

    if (k == 0)
        cout << power(3, n) << nl;
    else {
        int ans = 0;
        for (int i = 0; i <= min(k - 1, n - k); i++)
            ans = ans + 
                (choose(k - 1, i) * 
                 choose(n - k, i) % MOD * 
                 power(3, n - i - i - 1) % MOD);

        for (int i = 0; i <= min(k - 1, n - k - 1); i++)
            ans = ans + 
                (choose(k - 1, i) * 
                 choose(n - k, i + 1) % MOD * 
                 power(3, n - i - i - 2) % MOD);

        cout << ans % MOD << nl; 
    }
}
