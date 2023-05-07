using namespace std;
#include <bits/stdc++.h>
#include <string.h>
typedef long long ll;
typedef vector<int> vi;
typedef vector<pair<int,int>> vpi;
#define pb push_back
#define int long long
#define nl '\n'
#define rsz resize
#define sz(x) int(x.size())
#define all(x) begin(x), end(x)
#define no "no"
#define yes "yes"
#define print(x, y, z) for (int i = y; i <= z; i++) {cout << x[i] << " ";} cout << nl;


void solve() {
    int n, m, d; cin >> n >> m >> d;
    int a[n + 1] = {};
    int b[n] = {};
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        a[x] = i;
    }
    for (int i = 0; i < m; i++)
        cin >> b[i];

    int ans = INT_MAX;

    for (int i = 0; i < m - 1; i++) {
        if (a[b[i]] < a[b[i + 1]] && a[b[i]] + d >= a[b[i + 1]]) {
            ans = min(ans, a[b[i + 1]] - a[b[i]]);
            if (d < n - 1)
                ans = min(ans, d - (a[b[i + 1]] - a[b[i]]) + 1);

        } else {
            cout << 0 << nl;
            return;
        }
    }

    cout << ans << nl;
}   

int32_t main() {
    cin.tie(0)->sync_with_stdio(false);
    
    int t; cin >> t;
    while (t--)
        solve();
} 