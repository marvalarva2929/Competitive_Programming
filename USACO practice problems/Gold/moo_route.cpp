#include <bits/stdc++.h> 
#define int long long
#define nl " \n"
#define pi pair<int, int>
#define ff first
#define ss second

using namespace std;
const int mxn = 1e5, mxa = 1e6, MOD = 1e9 + 7;
int a[mxn];
int fact[mxa + 1], inv[mxa + 1];

int pow(int a, int b) {
    int ans = 1;
    a %= MOD;
    while (b) {
        if (b & 1) 
            ans = ans * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return ans;
}

int choose(int n, int k) {
    return fact[n] % MOD * inv[k] % MOD * inv[n - k] % MOD;
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int n; cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i], a[i] /= 2;
    
    fact[0] = 1;
    for (int i = 1; i <= mxa; i++) 
        fact[i] = i * fact[i - 1] % MOD; 

    inv[mxa] = pow(fact[mxa], MOD - 2);
    for (int i = mxa - 1; i >= 0; i--)
        inv[i] = inv[i + 1] * (i + 1) % MOD;
    
    int ans = 1;
    for (int i = 0; i < n - 1; i ++) {
        if (a[i] > a[i + 1]) ans = ans * choose(a[i], a[i + 1]) % MOD;
        else ans = ans * choose(a[i + 1] - 1, a[i] - 1) % MOD;
    }
    
    cout << ans % MOD << endl;
}
