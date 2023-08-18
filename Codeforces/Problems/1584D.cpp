#include <bits/stdc++.h>
#define int long long
#define nl endl
#define pi pair<int, int>
#define ff first
#define ss second

using namespace std;

int ask(int i, int j) {
    cout << "? " << i + 1  << " " << j + 1 << nl;
    int x; cin >> x;
    return x;
}

void solve() {
    int n; cin >> n;
    int a = ask(0, n - 1);

    int l = 0, r = n;
    while (l < r - 1) {
        int m = (l + r) >> 1;
        if (ask(0, m)) r = m;
        else l = m;
    }
    
    int i = l;
    int j = ask(i, n - 1) - ask(i + 1, n - 1) + i + 1;
    int k = ask(j, n - 1) - ask(j + 1, n - 1) + j;
    
    cout << "! " << ++i << " " << ++j << " " << ++k << nl;
}

signed main() {
    int t; cin >> t;
    while (t--)
        solve();
}
