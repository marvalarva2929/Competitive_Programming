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
    int n; cin >> n;
    int a[n] = {};
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a, a + n + 1);

    int cur = 1;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        // cout << a[i] << " " << a[i - 1] << nl;
        if (a[i] - 1 > a[i - 1]) { 
            ans += (a[i] - a[i - 1] - 1);
            a[i] -= (a[i] - a[i - 1] - 1);
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