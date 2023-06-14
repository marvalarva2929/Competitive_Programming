#include <bits/stdc++.h>
#define int long long
#define nl '\n'

using namespace std;
const int mxn = 3e5, MOD = 998244353;
bool isComp[mxn + 1];

int power(int a, int b) {
    int ans = 1;
    while (b) {
        if (b & 1) ans = ans * a % MOD;
        b >>= 1;
        a = a * a % MOD;
    }
    return ans % MOD;
}

int inv(int a) {
    return power(a, MOD - 2) % MOD;
}

int add(int x, int y)
{
    x += y;
    while(x >= MOD) x -= MOD;
    while(x < 0) x += MOD;
    return x;
}   

signed main() {
    cin.tie(0)->sync_with_stdio(false);
    
    isComp[1] = 1;
    for (int i = 2; i <= mxn; i++)
        if (!isComp[i])
            for (int j = i + i; j <= mxn; j += i)
                isComp[j] = 1;
   
    int n, m; cin >> n >> m;
    int cur = 1;
    int cnt = 1;
    int ans = 0;
    for (int i = 1; i <= n; i++)
        ans = add(ans, power(m % MOD, i));

    for (int i = 1; i <= n; i++) {
        if (cur > m) continue;
        if (!isComp[i]) cur *= i;
        cnt = cnt * ((m/cur) % MOD) % MOD;
        ans = add(ans, -cnt) % MOD;
    }
    
   
    cout << ans % MOD << nl;
}
