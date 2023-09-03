#include <bits/stdc++.h>
#define int long long
#define nl endl
#define pi pair<int, int>
#define ff first
#define ss second

using namespace std;
template<class T> using v = vector<T>;


int ask(int i, int j) {
    if (i == j) return 0;

    cout << "? " << i + 1 << " " << j + 1 << nl;
    int x; cin >> x;
    
    return x;
}

int getMax(int x, int y) {
    if (x == y) return x;

    int m = (x + y) >> 1;
    int le = getMax(x, m), ri = getMax(m + 1, y);
    
    return (ask(le, ri) - ask(le, ri - 1) >= 1 ? le : ri);
}

int solve() {
    int n; cin >> n;
    
    return getMax(0, n - 1) + 1;
}

signed main() {
    int t; cin >> t;
    while (t--) {
        int ret = solve();
        cout << "! " << ret << nl;
    }
}
