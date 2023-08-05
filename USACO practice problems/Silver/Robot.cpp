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
#define print(x, y, z) for (int i = y; i <= z; i++) {cout << x[i] << " ";} cout << nl;
int ans[41];


using P = pair<long long, long long>;
P operator+(P a, P b) { return {a.first + b.first, a.second + b.second}; }
P operator-(P a, P b) { return {a.first - b.first, a.second - b.second}; }

vector<pair<P, int>> allSubsets(vector<P> dirs) {
    vector<pair<P, int>> ps{{}};
    for (P dir : dirs) {
        ps.resize(ps.size() * 2);
        for (int i = 0; i < ps.size()/2; i++) {
            ps[i + ps.size()/2] = {ps[i].first + dir, ps[i].second + 1};
        }
    }
    sort(ps.begin(), ps.end());
    return ps;
}

int32_t main() {
    int n;
    cin >> n;
    P goal;
    cin >> goal.first >> goal.second;
    vector<P> dirs;
    for (int i = 0; i < n; i++) {
        int xx, yy;
        cin >> xx >> yy;
        dirs.push_back({xx, yy});
    }
    vector<pair<P, int>> left = allSubsets(vector<P>(dirs.begin(), dirs.begin() + n/2));
    vector<pair<P, int>> right = allSubsets(vector<P>(dirs.begin() + n/2, dirs.end()));
    reverse(right.begin(), right.end());
    P rest_prev = {1e10, 1e10};
    vector<int> with_num;
    int ib = 0;
    for (pair<P, int> sub : left) {
        P offset = sub.first;
        int num = sub.second;
        const P rest = goal - offset;
        if (rest != rest_prev) {
            rest_prev = rest;
            with_num = vector<int>(n - n/2 + 1);
            for (; ib < right.size() && right.at(ib).first > rest; ++ib);
            for (; ib < right.size() && right.at(ib).first == rest; ib++) ++with_num.at(right.at(ib).second);
        }

        for (int i = 0; i < with_num.size(); i++)
           ans[i + num] += with_num[i];
    }
    for (int i = 1; i <= n; i++)
        cout << ans[i] << nl;
}
