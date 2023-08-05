#include <bits/stdc++.h>
#define int long long
#define nl " \n"
#define pi pair<int, int>
#define ff first
#define ss second

using namespace std;
template<class T> using V = vector<T>;
const int MOD = 998244353, mxn = 5000;
int fact[mxn + 2], inf[mxn + 2];

int pow(int a, int b) {
    int ans = 1;
    a %= MOD;
    while (b) {
        if (b & 1) ans = ans * a % MOD;
        b >>= 1;
        a = a * a % MOD;
    }
    return ans % MOD;
}

int choose(int n, int k) {
    return fact[n] % MOD * inf[n - k] % MOD * inf[k] % MOD;
}

int inv(int x) {
    return pow(x, MOD - 2) % MOD;
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);
    
    int n, k; cin >> n >> k;

    fact[0] = 1;
    for (int i = 1; i <= n + 1; i++)
        fact[i] = fact[i - 1] * i % MOD;

    inf[n + 1] = inv(fact[n + 1]);
    for (int i = n; i >= 0; i--)
        inf[i] = inf[i + 1] * (i + 1) % MOD;

    V<bool> a(n);
    V<int> loc; 
    
    loc.push_back(-1); 
    for (int i = 0; i < n; i++) {
        char c; cin >> c;
        a[i] = c & 1;
        if (a[i]) loc.push_back(i); 
    }
    loc.push_back(n);

    int ans = 1;

    int l = 1, r = l + k - 1;
    bool first = 1;

    while (r < loc.size() - 1 && l <= r) {
        int left = loc[l - 1] + 1, right = loc[r + 1] - 1; 
        ans = ans + choose(right - left + 1, k) % MOD;
            
        if (!first) {
            ans = ans - choose((right - left + 1) - (loc[r + 1] - loc[r]), k - 1) % MOD;  
        } else ans--;
        
        first = 0;
        l++, r++;
    }
    
    while (ans < 0) ans += MOD;

    cout << (ans) % MOD << nl;
}


