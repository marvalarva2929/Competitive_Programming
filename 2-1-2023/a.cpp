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
    bool found = false;
    int s = 0;
    for (int i = 0; i < n; i++) 
        cin >> a[i], s += a[i];

    int new_s = INT_MIN;

    for (int i = 0; i < n - 1; i++) {
        new_s = max(new_s, (int)((a[i] > 0) ? -2 : 2) + (int)((a[i + 1] > 0) ? -2 : 2));
    }

    cout << s + new_s << nl;
}


int32_t main() {
    cin.tie(0)->sync_with_stdio(false);
    int t; cin >> t;
    while (t--)
        solve();
} 