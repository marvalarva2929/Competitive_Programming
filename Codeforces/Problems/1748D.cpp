#include <bits/stdc++.h>
#define int long long
#define pi pair<int, int>
#define ff first
#define ss second
#define nl " \n"

using namespace std;

void solve() {
    int a, b, d; cin >> a >> b >> d;
    int c = a | b;

    bitset<65> cc = c;
    bitset<65> dd = d;
    
    for (int i = 0; i < 31; i++)
        if (dd[i]) break;
        else if (cc[i]) {
            cout << -1 << nl;
            return;
        }
    
    while (!dd[0]) dd >>= 1;
    bitset<65> cur = 0;

    for (int i = 0; i < 35; i++)
        if (cc[i] && !cur[i])
            cur = cur.to_ullong() + (dd << i).to_ullong();
    
    cout << cur.to_ullong() << nl;    
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t; cin >> t;
    while (t--)
        solve();
}
