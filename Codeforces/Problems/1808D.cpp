#include <bits/stdc++.h>
#define int long long
#define nl " \n"
#define ff first
#define ss second
#define pi pair<int, int>

using namespace std;
const int mxn = 2e5;
int a[mxn], cnt[mxn+1][2];

signed main() {
    cin.tie(0)->sync_with_stdio(false);
    
    int n, k; cin >> n >> k;
    vector<map<int, vector<int>>> a(2);

    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        a[i % 2][x].push_back(i);
    }
     
    int ans = (k - 1)/2 * (n - k + 1);
    for (auto& xx : a) {
        for (auto& [x, occ] : xx) {
            for (int& y : occ) {
                int l = max(k - y + 1, y - k + 1),
                    r = min(n + n - y - k + 1, y - 2);

                if (l <= r) ans -= upper_bound(occ.begin(), occ.end(), r) - lower_bound(occ.begin(), occ.end(), l);
            } 
        }
    }

    cout << ans << nl;
}
