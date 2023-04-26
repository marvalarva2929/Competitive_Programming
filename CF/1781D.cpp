using namespace std;
#include <bits/stdc++.h>
#define int long long
#define nl '\n'

set<int> divisors(int x) {
    set<int> ret;
    for (int i = 1; i * i <= x; i++)
        if (!(x % i))
            ret.insert(i),
            ret.insert(x/i);
    return ret;
}

bool isSq(int a) {
    return ((int)sqrt(a) * (int)sqrt(a)) == a;
}

void solve() {
    int n; cin >> n;
    int a[n] = {};
    for (int i = 0; i < n; i++)
        cin >> a[i];

    vector<int> xs;
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            for (int divisor : divisors(a[j] - a[i])) {
                int q = divisor + ((a[j] - a[i]) / divisor);
                // cout << a[j] - a[i] << " " << divisor << nl;
                if (!(q % 2)) {
                    q /= 2;
                    if (q * q < a[j]) continue;
                    xs.push_back((q * q) - a[j]);
                    // cout << (q * q) - a[j] << nl;
                }
            }

    int ans = 1;
    for (int x : xs) {
        int c_ans = 0;
        for (int i = 0; i < n; i++)
            if (isSq(a[i] + x))
                c_ans++;
        ans = max(ans, c_ans);
    }
    cout << ans << nl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t; cin >> t;
    while (t--)
        solve();
}