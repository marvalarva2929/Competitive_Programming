#include <bits/stdc++.h>
#define int long long
#define pi pair<int, int>
#define ff first
#define ss second
#define nl " \n"

using namespace std;
const int MOD = 1e9 + 7, bit = 40;

template<class T> using V = vector<T>;

int power(int a, int b) {
    int ans = 1;
    while (b) {
        if (b & 1) ans = ans * a % MOD;
        b >>= 1;
        a = a * a % MOD;
    }
    return ans;
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int n; cin >> n;
    V<int> a(n);
    V<int> cnt(bit);

    for (int i = 0; i < n; i++)
        cin >> a[i];

    for (int i = 0; i < n; i++) {
        int x = 0;
        while (!(a[i] & 1)) {
            a[i] >>= 1;
            x++; 
        }
        cnt[x]++;     
    }
    int y;
    int ans = (power(2, n) - power(2, y = n - cnt[0])) % MOD;
    
    for (int l = 1; l < bit; l++) {
        int x = y;
        y -= cnt[l];
        if (x - y < 2) continue;
        ans = ans + power(2, x - 1) - power(2, y) % MOD;
    }
    
    while (ans < 0) ans += MOD;

    cout << ans % MOD << nl;
}
