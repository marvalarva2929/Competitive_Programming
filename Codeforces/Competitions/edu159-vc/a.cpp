#include <bits/stdc++.h>
#define int long long
#define pi pair<int, int>
#define ff first
#define ss second
#define nl " \n"

using namespace std;

bool solve() {
    int n; cin >> n;
    char l = 'c';
    int o = 0, z = 0;

    for (int i = 0; i < n; i++) {
        char c; cin >> c;
        if (i && c != l) o = INT_MAX;
        o += (c == '0'), z += (c == '1');
        l = c; 
    }
    return o > z;
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t; cin >> t;
    while (t--)
        cout << (solve() ? "YES" : "NO") << nl;
}
