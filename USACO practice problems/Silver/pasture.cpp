using namespace std;
#include <bits/stdc++.h>
#define int long long
#define nl '\n'
#define MAX (int)2510
#define Point pair<int, int>

int a[MAX][MAX];

bool ycomp(const Point & a, const Point & b) {
    return a.second < b.second;
}

int rsum(int x1, int y1, int x2, int y2) {
    x1++, x2++, y1++, y2++;
    return a[x2][y2] - a[x2][y1 - 1] - a[x1 - 1][y2] + a[x1 - 1][y1 - 1];
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);
    int n; cin >> n;
    vector<Point> points;

    for (int i = 0; i < n; i++) {
        int x, y; cin >> x >> y;
        points.push_back({x, y});
    }     
    sort(points.begin(), points.end());
    for (int i = 0; i < n; i++)
        points[i].first = i + 1;
    sort(points.begin(), points.end(), ycomp);
    for (int i = 0; i < n; i++)
        points[i].second = i + 1;

    for (int i = 0; i < n; i++)
        a[points[i].first][points[i].second] = 1;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            a[i][j] += a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1];

    // for (int i = 1; i <= n; i++) {
    //     for (int j = 1; j <= n; j++)
    //         cout << a[i][j] << " ";
    //     cout << nl;
    // }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            int x1 = min(points[i].first, points[j].first) - 1;
            int x2 = max(points[i].first, points[j].first) - 1;
            ans += (rsum(0, i, x1, j)) * (rsum(x2, i, n - 1, j));
        }
    }
    cout << ans + 1 << nl;
}