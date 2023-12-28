#include <bits/stdc++.h>
#define nl " \n"
#define pi pair<int, int>
#define ff first
#define ss second

using namespace std;

int solve() {
    int n, m; cin >> n >> m;
    
    int x = 0;
    for (int i = 31; i >= 0; i--) {
        int nb = (n >> i) & 1, mb = (m >> i) & 1;

        if (nb && !mb) { return x; }
        if (mb && !nb) x += (1 << i); 
    }
     
    int cnt = 0;
    while ((m >> cnt) & 1) cnt++, x >>= 1;
    x += 1;
    x <<= cnt;

    return x;
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);
    int t; cin >> t;
    while (t--)
        cout << solve() << nl;
}
