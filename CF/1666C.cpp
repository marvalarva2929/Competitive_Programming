using namespace std;
#include <bits/stdc++.h>
#define int long long
#define nl '\n'
#define no "no"
#define yes "yes"
#define print(x, y, z) for (int i = y; i <= z; i++) {cout << x[i] << " ";} cout << nl;
#define pi pair<int, int>
#define pii pair<pi, pi>
#define mp(x, y) make_pair(x, y)
#define x first
#define y second

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

void solve() {
    pi one, two, three;
    cin >> one.x >> one.y >> two.x >> two.y >> three.x >> three.y;
    vector<pi> points = {one, two, three};
    vector<pii> segs;

    sort(points.begin(), points.end(), [&](const pi & a, const pi & b) -> bool {
        return a.x < b.x;
    });
    pi midx = points[1];

    sort(points.begin(), points.end(), [&](const pi & a, const pi & b) -> bool {
        return a.y < b.y;
    });
    pi maxy = points[2];
    pi miny = points[0];

    segs.push_back(mp(mp(midx.x, miny.y), mp(midx.x, maxy.y)));
    segs.push_back(mp((miny == midx ? points[1] : miny), mp(midx.x, (miny == midx ? points[1].y : miny.y))));
    segs.push_back(mp((maxy == midx ? points[1] : maxy), mp(midx.x, (maxy == midx ? points[1].y : maxy.y))));

    cout << 3 << nl;
    for (auto seg : segs)
        cout << seg.x.x << " " << seg.x.y << " " << seg.y.x << " " << seg.y.y << nl;

    
}   

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    // int t; cin >> t;
    // while (t--)
        solve();
}