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

int bit = 1;
int ans = 0;

int32_t main() {
    int l, r; cin >> l >> r;
    int diff = r - l;
    int pos = 0;
    while (bit <= diff) {
        ans += bit;
        bit *= 2;
        pos++;
    }
    while (bit <= r) {
        if (((r >> pos) ^ (l >> pos)) & 1ll) 
            ans += bit;
        bit *= 2;
        pos++;
    }
    cout << ans << nl;
} 