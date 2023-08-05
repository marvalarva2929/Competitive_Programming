#include <bits/stdc++.h>
#define int long long
#define nl endl
#define ff first
#define ss second
#define pi pair<int, int>

using namespace std;
    
int ask(int a, int b) {
    cout << "? " << a << " " << a + b << nl;
    int x; 
    cin >> x;
    return x;
}

void solve() {
    int r = 0;
    for (int i = 1; i <= 30; i++) {
        int res = ask((1 << (i - 1)) - r, (1 << i));
        if (res == (1 << i)) r += (1 << (i - 1));
    }
    cout << "! " << r << nl;
}

signed main() {
    int t; cin >> t;
    while (t--)
        solve();
}
