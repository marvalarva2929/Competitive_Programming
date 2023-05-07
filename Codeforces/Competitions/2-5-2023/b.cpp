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
    int n, b, h; cin >> n >> b >> h;
    int a[n] = {};
    int c[n] = {};
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> c[i];

    int mn = INT_MIN, mx = INT_MAX;

    for (int i = 0; i < n; i++) {
        mn = max(mn, (c[i] + h) - (a[i] + b));
        mx = min(mx, (c[i] - h) - (a[i] - b));
    }
    // cout << mn << " " << mx << nl;
    cout << (mn <= mx ? yes : no ) << nl;
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(false);

    int t; cin >> t;
    while (t--)
        solve();
} 