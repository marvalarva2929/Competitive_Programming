#include <bits/stdc++.h>
#define int long long
#define nl " \n"
#define pi pair<int, int>
#define ff first
#define ss second

using namespace std;
const int mxn = 3e5;
const int MOD = 998244353;

int a[mxn + 1];
int fact[mxn + 1];
int invf[mxn + 1];

int power(int a, int b) {
    int ans = 1;
    while (b) {
        if (b & 1) ans = ans * a % MOD;
        b >>= 1;
        a %= MOD;
        a = a * a % MOD;
    }
    return ans % MOD;
}

int inv(int x) { return power(x, MOD - 2) % MOD; };

int choose(int n, int k) {
    return fact[n] % MOD * invf[k] % MOD * invf[n - k] % MOD;
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int n, m; cin >> n >> m;

    fact[0] = 1;
    for (int i = 1; i <= m; i++)
        fact[i] = i * fact[i - 1] % MOD,
        fact[i] %= MOD; 
    
    invf[m] = inv(fact[m]);
    
    for (int i = m; i > 0; i--)
        invf[i - 1] = invf[i] * i % MOD;
    int cur = 0; 

    for (int i = 1; i <= n; i++ ) {
        int tcur = cur; 
        cin >> a[i];
        tcur += a[i];
        a[i] += cur;
        cur = tcur; 
    }

    int t = 0;
    int ans = 0;
    
    //for (int i = 0; i <= n; i++)
    //    cout << a[i] << nl[i == n];
    
    int r = 0;
    
    if (a[n] % 2 == 0) {
        for (int i = 0; i < n && r < n; i++) {
            while (r < n - 1 && a[r] - a[i] < a[n]/2) r++;          
            //cout << i << " " << r << nl; 
            t += a[r] - a[i] == a[n]/2; 
        }
    }
   
    //cout << t << nl;

    for (int k = 0; k <= t; k++) {
        int cur = fact[k];
        cur = cur * choose(m, k) % MOD;
        cur = cur * choose(t, k) % MOD;
        cur = cur * power(m - k, n - (2 * t)) % MOD;
        cur = cur * power((m - k) * (m - k - 1), t - k) % MOD;
        
        //cout << k << " : " << cur << nl;

        ans = ans + cur % MOD;
    }
    
    cout << ans % MOD << nl;
}

