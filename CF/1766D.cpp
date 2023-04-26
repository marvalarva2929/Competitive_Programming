using namespace std;
#include <bits/stdc++.h>
#define int long long
#define nl '\n'
#define MAX (int)1e7 + 10
int ld[MAX];
vector<int> primes;

vector<int> factorize(int x) {
    vector<int> factors;
    while (ld[x]) {
        factors.push_back(ld[x]);
        x /= ld[x];
    }
    return factors;
}

void solve() {
    int x, y; cin >> x >> y;
    if (y > x) swap(x, y);

    vector<int> factors = factorize(x - y);

    int ans = INT_MAX;

    for (int factor : factors) {
        ans = min((factor - (x % factor)) % factor, ans);
        // cout << factor << " " << x % factor << nl;
    }   

    if (ans == INT_MAX)
        cout << -1 << nl;
    else cout << ans << nl;

}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    primes.push_back(2);
    ld[2] = 2;

    for (int i = 2; i < MAX; i += 2)
        ld[i] = 2;

    for (int i = 3; i < MAX; i += 2)
        if (!ld[i]) {
            primes.push_back(i);
            for (int j = i; j < MAX; j += i)
                ld[j] = i;
        }

    int t; cin >> t;
    while (t--)
        solve();
}