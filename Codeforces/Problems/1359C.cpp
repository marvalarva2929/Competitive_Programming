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
#define f first
#define s second
#define print(x, y, z) for (int i = y; i <= z; i++) {cout << x[i] << " ";} cout << nl;


void solve() {
    int h, c, t;
    cin >> h >> c >> t;
    if ((h + c)/2 >= t) {
        cout << 2 << nl;
        return;
    }

    int k = ((h - t) / ((2 * t) - h - c));

    int a = abs(((k * (h + c)) + h) - t * (2 * k + 1)) * (2 * k + 3);
    int b = abs((((k + 1) * (h + c)) + h) - t * (2 * k + 3)) * (2 * k + 1);

    // cout << k <<": " << a << ": " << b << nl;
    if (a <= b) 
        cout << 2 * k + 1 << nl;
    else cout << 2 * k + 3 << nl;
}

int32_t main() {
    int t; cin >> t;
    while (t--)
        solve();
} 