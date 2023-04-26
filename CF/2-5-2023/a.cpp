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
    int a = 0, b = 0;
    a += 1, n -= 1;
    int i = 2;

    while (n > 0) 
        if ((i/2) % 2) {
            b += min((int)n, i + i + 1),
            n -= i + i + 1;
            i += 2;
        } else { 
            a += min((int)n, i + i + 1),
            n -= i + i + 1;
            i += 2;
        } 

    cout << a << " " << b << nl;
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(false);
    int t; cin >> t;
    while (t--)
        solve();
} 