#include <bits/stdc++.h>
#define int long long
#define nl " \n"
#define pi pair<int, int>
#define ff first
#define ss second
#define MOD ((int)998244353)

using namespace std;

const int mxn = 5050, mxa = 1e6;
int a[mxn], cnt[mxa + 1], fact[mxn];
int f[mxn][mxn];
bool isComp[mxa + 1];
set<int> pri, comp;
vector<int> primes;
int ans = 1;

int pow(int a, int b) {
    int ans = 1;
    while (b) {
        if (b & 1)
            ans = ans * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return ans;
}

int inv(int a) {
    return ((pow(a, MOD - 2)) % MOD);
}

int dp(int x, int y) {
    int &ans = f[x][y];

    if (ans >= 0) return ans;

    if (x == (int)primes.size())
        return ans = (y == 0);
    
    ans = inv(fact[cnt[primes[x]]]) * dp(x + 1, y) % MOD; 

    if (y > 0)
        ans = (ans % MOD) + (inv(fact[cnt[primes[x]] - 1]) * dp(x + 1, y - 1) % MOD); 
    
    return ans % MOD;
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);
    
    memset(f, -1, sizeof f);
        
    fact[0] = 1;
    for (int i = 1; i < mxn; i++)
        fact[i] = (fact[i - 1] % MOD) * (i % MOD) % MOD;

    isComp[1] = 1;
    for (int i = 2; i <= mxa; i++)
        if (!isComp[i])
            for (int j = i + i; j <= mxa; j += i)
                isComp[j] = 1;
    
    int n; cin >> n;
    for (int i = 0; i < n * 2; i++)
        cin >> a[i],
        cnt[a[i]]++;

    for (int i = 0; i < n * 2; i++)
        if (!isComp[a[i]])
            pri.insert(a[i]);
        else comp.insert(a[i]);

    if (pri.size() < n) {
        cout << 0 << nl;
        return 0;
    }
    
    for (int prime : pri)
        primes.push_back(prime);
    
    int ans = dp(0, n);
    
    for (int x : comp)
        ans = ans * inv(fact[cnt[x]]) % MOD;

    ans = fact[n] * ans % MOD;

    cout << ans << nl;
}
