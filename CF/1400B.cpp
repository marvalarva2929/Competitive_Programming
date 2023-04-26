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
    int p, f, ns, nw, s, w; cin >> p >> f >> ns >> nw >> s >> w;
    int ans = LONG_LONG_MIN;
    if (w < s) {
        swap(w, s);
        swap(nw, ns);
    }
    int up = min(ns, p/s);


    for (int s1 = 0; s1 <= up; s1++) {
        int w1 = min(nw, (p - (s1 * s))/w);
        int s2 = min(ns - s1, f/s);
        int w2 = min(nw - w1, (f - (s2 * s))/w);
        // cout << s1 << " : " << w1 << " : " << s2 << " : " << w2 << nl;
        ans = max(ans, s1 + s2 + w1 + w2);
    }
    cout << ans << nl;
}


int32_t main() {
    int t; cin >> t;
    while (t--)
        solve();
} 