#include <bits/stdc++.h>
#define int long long
#define pi pair<int, int>
#define ff first
#define ss second
#define nl " \n"

using namespace std;
int n, p, l, s, ts;

bool check(int x) {
    int stu = n - x;
    int got = (stu * l) + (s * min(stu * 2, ts));
    return got >= p;
}

int solve() {
    cin >> n >> p >> l >> s;
    ts = (n + 6) / 7;

    int l = 0, h = n;
    while (l < h) {
        int m = ((l + h) >> 1) + 1;
        if (check(m)) l = m;
        else h = m - 1;
    }
     
    return l;
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t; cin >> t;
    while (t--)
        cout << solve() << nl;
}
