#include <bits/stdc++.h>
#define int long long
#define nl " \n"
#define ff first
#define ss second
#define pi pair<int, int>

using namespace std;
const int mxn = 1e5;
int a[mxn];

int solve() {
    int n, k; cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    
    if (k != 4) {
        int mn = INT_MAX;
        for (int i = 0; i < n; i++) {
            int cnt = 0;
            while ((a[i] + cnt) % k) cnt++;
            mn = min(mn, cnt);
        }
        return mn; 
    } else {
        int cnt = 0;
        for (int i = 0; i < n; i++)
            cnt += !(a[i] % 2) + !(a[i] % 4);
        if (cnt >= 2) return 0;
        else if (cnt == 1) return 1;
        else {
            int mn = 2;
            for (int i = 0; i < n; i++) {
                int cnt = 0;
                while ((a[i] + cnt) % k) cnt++;
                mn = min(mn, cnt);
            }
            return mn; 
        };
    }
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t; cin >> t;
    while (t--)
        cout << solve() << nl;
}
