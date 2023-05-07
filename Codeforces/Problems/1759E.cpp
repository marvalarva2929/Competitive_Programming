using namespace std;
#include <bits/stdc++.h>
#define nl '\n'
#define int long long
#define MAX (int)2e5 + 10
int a[MAX];

void solve() {
    int n, h1; cin >> n >> h1;
    int ones = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a, a + n);

    int ans = 0;
    for (int i = 0; i < 3; i++) { // order we use the blue serum
        bool useBlue[3] = {}; useBlue[i] = 1;
        int used = 0;
        int j = 0;
        int eaten = 0;
        int h = h1;
        
        while (j < n && eaten < n && used < 3) {
            while (a[j] < h && j < n) {
                h += (a[j]/2);
                // cout << "eating " << a[j] << " : " << h << nl;
                j++;
                eaten++;
            }
            // cout << j << " : " << a[j] << " : " << h << nl;
            while (j < n && a[j] >= h && used < 3) {
                if (useBlue[used] && used < 3) {
                    used++;
                    h *= 3;
                    // cout << "used blue" << h << nl;
                } else if (used < 3) {
                    used++;
                    h *= 2;
                    // cout << "used green" << h << nl;
                } 
            }
            while (a[j] < h && j < n) {
                h += (a[j]/2);
                // cout << "eating " << j << " : " << h << nl;
                j++;
                eaten++;
            }
        }
        ans = max(ans, eaten);
    }

    cout << ans << nl;
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    int t; cin >> t;
    while(t--)
        solve();
}
