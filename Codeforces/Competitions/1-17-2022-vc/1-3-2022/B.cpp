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
#define no "NO"
#define yes "YES"
#define print(x, y, z) for (int i = y; i <= z; i++) {cout << x[i] << " ";} cout << nl;

void solve() {
    int n; cin >> n;

    if (!(n % 2)) {
        cout << yes << nl;
        // cout << -1 << " " << 1 << nl;
        for (int i = 0; i < n; i++) 
            cout << (((i % 2) == 0) ? -1 : 1) << " ";
        cout << nl;
        return;
    } else {
        int a = n/2, b = a + 1;
        int x, y;
        // cout << a << " " << b << nl;
        bool is = false;
        for (int i = 1; i <= 5000; i ++){
            if (((a * i) - 1) % b == 0) {
                x = ((a * i) / a);
                y = (((a * i) - 1) / b);
                is = true;
                break;
            }
        }

        if (!is || x == 0 || y == 0) {
            cout << no << nl; 
            return;
        } else {
            cout << yes << nl;
            for (int i = 0; i < n; i++)
                cout << (i % 2 ? x : -y) << " ";
            cout << nl;
            return;
        }
    }
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(false);

    int t; cin >> t;
    while (t--)
        solve();
} 