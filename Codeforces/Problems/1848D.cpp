#include <bits/stdc++.h>
#define int long long
#define nl " \n"
#define pi pair<int, int>
#define ff first
#define ss second

using namespace std;

void solve() {
int y, n; cin >> y >> n; 
    int ans = 0;
    
    if (y % 10 == 5) 
        ans = max(ans, (y + 5) * (n - 1));
    if (y % 10 == 0)
        ans = max(ans, y * n);

    while (y % 10 != 2 && y % 10 != 0 && n > 0) {
        ans = max(ans, y * n); 
        y += y % 10;
        n--; 
    }

    if (y % 10 != 0 && n > 0) {
        int e[4] = {0, 2, 4, 8};
        for (int i = 0; i < 4; i++) {
            y += e[i];
            int fup = ((20 * n) - (4 * y) + 159) / 160.0;
            int fdown = ((20 * n) - (4 * y)) / 160.0;
            
            fup = max((int)0, fup);
            fdown = max((int)0, fdown);

            ans = max(
                    {
                        ans, 
                        (int)(n - 4 * fup) * (int)(20 * fup + y), 
                        (int)(n - 4 * fdown) * (int)(20 * fdown + y)
                    }
                    );
            n--;
        } 
    }

    cout << ans << nl;

}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t; cin >> t;
    while (t--)
        solve();
}
