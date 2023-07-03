#include <bits/stdc++.h>
#define int long long
#define nl " \n"

using namespace std;

const int mxn = 1e5;
int a[mxn], b[mxn];

void solve() {
    int n; cin >> n;
    
    for (int i = 0; i < n; i++) {
        char c; cin >> c;
        a[i] = c - 'a';
    }

    for (int i = 0; i < n; i++) {
        char c; cin >> c;
        b[i] = c - 'a';
    }
    
    int fdiff = 0, bdiff = 0;

    for (int i = 0; i < n; i++)
        fdiff += a[i] != b[i],
        bdiff += a[i] != b[n - i - 1];
    
    if (fdiff == 0 && bdiff == 0) {
        cout << 0 << nl;
        return;
    }

    if (fdiff != 0 && bdiff == 0) { 
        cout << 2 << nl;
        return; 
    }
        
    cout << min((2 * fdiff) - (fdiff % 2), (2 * bdiff) - (!(bdiff % 2))) << nl; 
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t; cin >> t;
    while (t--)
        solve();
}
