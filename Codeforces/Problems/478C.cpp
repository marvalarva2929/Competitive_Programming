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


int32_t main() {
    int r, g, b;
    int ans = 0;
    cin >> r >> g >> b;
    int ma = max(max(r, g), b);
    int tot = r + g + b;
    if (ma >= (tot - ma) * 2) {
        cout << (tot - ma) << nl;
    } else cout << tot/3 << nl;
} 