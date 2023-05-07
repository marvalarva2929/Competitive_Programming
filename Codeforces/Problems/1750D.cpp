using namespace std;
#include <bits/stdc++.h>
#define int long long
#define nl '\n'
#define no "no"
#define yes "yes"
#define print(x, y, z) for (int i = y; i <= z; i++) {cout << x[i] << " ";} cout << nl;
#define mod 998244353
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

set<int> factorize(int n) {
    int i = 2;
    set<int> ans;
    while (i * i <= n) {
        while (!(n % i))
            ans.insert(i),
            n /= i;

        i++;
    }
    if (n > 1)
        ans.insert(n);

    return ans;
}

void solve() {
    int n, m; cin >> n >> m;
    int a[n] = {}, b[n] = {};
    for (int i = 0; i < n; i++)
        cin >> a[i];
    
    for (int i = 1; i < n; i++) 
        if (a[i - 1] % a[i]) {
            cout << 0 << nl;
            return;
        }
    
    set<int> factors = factorize(a[0]);

    b[0] = 1;

    for (int i = 1; i < n; i++) {
        int left = a[i - 1] / a[i];
        int till = m / a[i];
        vector<int> curr;
        // how many numbers [1...left] are not factors of till

        for (int factor : factors) 
            if (!(left % factor))
                curr.push_back(factor);

        int sz = curr.size();
        for (int j = 0; j < (1 << sz); j++) {
            int prod = 1;
            int cnt = 0;
            for (int k = 0; k < sz; k++)
                if (1 & (j >> k))
                    prod = (prod * curr[k]) % mod, 
                    cnt++;

            if (cnt % 2) 
                b[i] -= (till / prod);
            else b[i] += (till / prod);
        }        
    }

    int ans = 1;
    for (int i = 0; i < n; i++)
        ans = (ans * (b[i] % mod)) % mod;

    cout << ans % mod << nl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t; cin >> t;
    while (t--)
        solve();
}