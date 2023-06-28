#include <bits/stdc++.h>
#define int long long
#define nl " \n"

using namespace std;

const int MOD = 1e9 + 7;

vector<int> factors(int n) {
    vector<int> ret;

    for (int i = 1; i * i <= n; i++)
        if (n % i == 0) {
            ret.push_back(i); 
            if (i * i != n)
                ret.push_back(n/i);
        }
    
    return ret;
}

int lcm(int n, int m) {
    return (n * m) / __gcd(n, m); 
}

int power(int a, int b) {
    int ans = 1;
    while (b) {
        if (b&1)
            ans = ans * a % MOD;
        b >>= 1;
        a = a * a % MOD;
    }
    return ans % MOD;
}

void solve() {
    int b, q, y; cin >> b >> q >> y;
    int c, r, z; cin >> c >> r >> z;

    int mb = b + ((q * (y - 1)));
    int mc = c + ((r * (z - 1)));

    if (b > c || mb < mc) {
        cout << 0 << nl;
        return;
    } else if (r % q || (c - b) % q) {
        cout << 0 << nl;
        return;
    }
   
    if (b > c - r || mb < mc + r) {
        cout << -1 << nl;
        return;
    }

    vector<int> poss = factors(r);
    int ans = 0;

    for (int p : poss) {
        if (lcm(p, q) == r)
            ans = ans + power(r/p, 2) % MOD;
    }
    
    cout << ans % MOD << nl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t; cin >> t;
    while (t--)
        solve();
}
