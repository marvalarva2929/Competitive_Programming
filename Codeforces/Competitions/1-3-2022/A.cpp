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
    bool a[n] = {};
    for (int i = 0; i < n; i++) {
        char c; cin >> c;
        a[i] = (c == 'R');
    }

   for (int i = 0; i < n - 1; i++)
        if (a[i] && !a[i + 1]) {
            cout << 0 << nl;
            return;
        } else if (i < n - 2 && a[i] && a[i + 1] && !a[i + 2]) {
            cout << i + 2 << nl;
            return;
        } else if (!a[i] && a[i + 1]) {
            cout << i + 1 << nl;
            return;
        }

    cout << -1 << nl;
    return;
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(false);

    int t; cin >> t;
    while(t--)
        solve();
} 