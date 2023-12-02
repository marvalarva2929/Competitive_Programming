#include <bits/stdc++.h>
#define int long long
#define nl " \n"
#define pi pair<int, int>
#define ff first
#define ss second

using namespace std;
const int mxn = 2e5, MOD = 998244353;
int a[mxn + 1], fact[mxn + 1];

int power(int a, int b) {
    int ans = 1;
    a %= MOD;

    while (b) {
        if (b & 1) ans = ans * a % MOD;
        b >>= 1;
        a = a * a % MOD;
    }
    return ans % MOD;
}

int inv(int x) { return power(x, MOD - 2) % MOD; }

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int n, k; cin >> n >> k;

    fact[0] = 1;
    for (int i = 1; i <= n; i++)
        fact[i] = fact[i - 1] * i % MOD;
    
    a[n] = 1;
    for (int i = n - 1; i >= 0; i--) {
        int x = n - i;
        //cout << i << " : " << (x + 1) << " " << (x)  << nl;
        a[i] = a[i + 1] * power(((x + 1) * inv(x)), max((int)0, k + i + 1 - n)) % MOD; 
    }
    
    for (int i = 0; i < n; i++) {
        a[i] = a[i] -  a[i + 1] % MOD; 
        while (a[i] < 0) a[i] += MOD; 
        //cout << a[i] << " "; 
    }
    //cout << a[n] << nl; 
    

    int s = 0;
    for (int i = 0; i <= n; i++)
        s = s + (a[i] * inv(fact[i]) % MOD) % MOD;
    s %= MOD;

    s = s * fact[n] % MOD;
    
    while (s < 0) s += MOD;

    cout << s % MOD << nl;
}
