using namespace std;
#include <bits/stdc++.h>
#define int long long
#define nl '\n'

int n, m;
string s;

void solve() {
    cin >> n >> m >> s;

    int minx = 0, miny = 0, maxx = 0, maxy = 0;
    int x = 0, y = 0;

    pair<int, int> mx[s.size()] = {};

    for (int i = 0; i < s.size(); i++) {
            if      (s[i] == 'L') miny = min(miny, --y);
            else if (s[i] == 'R') maxy = max(maxy, ++y);
            else if (s[i] == 'U') minx = min(minx, --x);
            else               maxx = max(maxx, ++x);

        if (maxx - minx >= n) {
            if (x == minx) minx++;
            break;
        }
        if (maxy - miny >= m) {
            if (y== miny) miny++;
            break;
        }
    }

    cout << 1 - minx << " " << 1 - miny << nl;

}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t; cin >> t;
    while (t--)
        solve();
}