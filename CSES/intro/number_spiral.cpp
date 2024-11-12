#include <bits/stdc++.h>
#define int long long

using namespace std;

int getx(int x) {
    if (x % 2 == 0) return getx(x - 1) + 1; 
    int n = x - 1;
    return 1 + (n/2 * (3 + (3 + ((n - 1) * 2))));
}

void solve() {
    int x, y; cin >> x >> y;
    swap(x, y);
    
    int tx = max(x, y);
    int dist = y + tx - x;
    if (y < x) dist = y; 
    int atx = getx(tx);
    dist--;    

    if (tx % 2) atx -= dist;
    else atx += dist;
    
    cout << atx << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);
    int t; cin >> t;
    while (t--)
        solve();
}
