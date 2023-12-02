#include <bits/stdc++.h>
#define int long long
#define nl " \n"
#define pi pair<int, int>
#define ff first
#define ss second

using namespace std;
const int mxn = 3e5, MOD = 998244353;
int u[mxn+1];
int n;

int power(int a, int b) {
    int ans = 1;
    while (b) {
        if (b & 1) ans = ans * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return ans % MOD;
}

int nums(vector<int> a, int b) {
    int ans = 0;
        
    vector<int> pref(n);
    vector<vector<int>> cnt(2, vector<int>(n));
    vector<vector<int>> sum(2, vector<int>(n));

    pref[0] = a[0]; 
    cnt[pref[0]][0]++;
    sum[pref[0]][0]++; 

    for (int i = 1; i < n; i++)
        pref[i] = (pref[i - 1] + a[i]) % 2,
        cnt[pref[i]][i]++,
        sum[pref[i]][i] += i + 1;

    for (int i = n - 2; i >= 0; i--)
        for (int j = 0; j < 2; j++)
            cnt[j][i] += cnt[j][i + 1],
            sum[j][i] += sum[j][i + 1];
    
    for (int i = 0; i < n; i++) {
        int c = cnt[(i ? !pref[i - 1] : 1)][i] % MOD;
        int s = sum[(i ? !pref[i - 1] : 1)][i] % MOD;
        ans = ans + s % MOD - (c * i % MOD) % MOD;
    }
    ans %= MOD; 
    return ans * power(2, b) % MOD;
}

void solve() {
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    
    int ans = 0;
        
    for (int i = 0; i < 32; i++) {
        vector<int> na(n);
        for (int j = 0; j < n; j++)
            na[j] = (a[j] >> i) & 1;
        
        ans = ans + nums(na, i) % MOD;
    }
    
    cout << ans % MOD << nl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t = 1;
    while (t--)
        solve();
}

