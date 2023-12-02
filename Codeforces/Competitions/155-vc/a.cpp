#include <bits/stdc++.h>
#define int long long
#define nl " \n"
#define pi pair<int, int>
#define ff first
#define ss second

using namespace std;

void solve() {
    int n; cin >> n;
    int w = 0, f = 0;
    bool no = 0;
    for (int i = 0; i < n; i++) {
        int s, e; cin >> s >> e;
        if (i == 0) w = s, f = e;
        else if (s >= w && e >= f) { no = 1; }
    }
    
    cout << (no ? -1 : w)<< nl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t; cin >> t;
    while (t--)
        solve();
}

