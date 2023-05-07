#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#define int long long
#define nl '\n'
using namespace std;

int32_t main() {
    int t;
    cin >> t;
    for (int p = 0; p < t; p++) {
        int n, x;
        cin >> n >> x;
        if (n % x != 0) {
            cout << -1 << nl;
            continue;
        } // x must be a factor of n
        vector<int> ans(n + 1, 0);
        ans[1] = x;
        ans[n] = 1;

        vector<int> factors;
        int m = n/x;
        while (m > 1) {
            for (int i = 2; i <= m; i++) {
                while (m % i == 0) {
                    factors.push_back(i);
                    m /= i;
                }
            }
        }

        int curr = x;
        int iter = 0;
        while (iter < factors.size()) {
            int f = factors[iter++];
            ans[curr] = curr * f;
            curr *= f;
        }

        for (int i = 2; i < n; i++) {
            if (ans[i] == 0) ans[i] = i;
        }

        for (int i = 1; i <= n; i++) cout << ans[i] << ' ';
        cout << nl;
        // for (int fa : factors) cout << fa << ' ' << nl;
    }
}