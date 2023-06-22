#include <bits/stdc++.h>
#define int long long
#define nl " \n"

using namespace std;
const int MOD = 1e9 + 7;
const int mxn = 1e5;
int fact[mxn + 1];

int power(int a, int b) {
    int ans = 1;
   
    while (b) {
        if (b & 1)
            ans = a * ans % MOD;
        a = a * a % MOD;
        b >>= 1;
    }

    return ans % MOD;
}

int inv(int x) {
    return power(x, MOD - 2) % MOD;
}

int choose(int n, int k) {
    return fact[n] * inv(fact[k]) % MOD * inv(fact[n - k]) %  MOD;
}


signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int n, k; cin >> n >> k;
        
    if (k >= n) cout << power(2, n) << nl;

    else {
        int ans = 0;
        
        fact[0] = 1;
        for (int i = 1; i <= n; i++)
            fact[i] = i * fact[i - 1] % MOD;
        
        for (int i = 0; i <= k; i++)
            ans = ans + choose(n, i) % MOD;

        cout << ans % MOD << nl;
    }
}
