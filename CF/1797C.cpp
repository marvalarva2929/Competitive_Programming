#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'

int ask(int x, int y) {
    cout << "? " << x << " " << y << nl;
    cout.flush();
    int ans; cin >> ans;
    return ans;   
}

void answer(int x, int y) {
    cout << "! " << x << " " << y << nl;
    cout.flush(); 
}

void solve() {
    int n, m; cin >> n >> m;
    int ax, ay;
    
    bool bot = false;

    int dist = ask(1, 1);
    int dist2 = 0;
    int dist3 = 0;

    if (1 + dist > n) {
        bot = true;
        goto bottom;
    }

    if (1 + dist > m) {
        dist2 = ask(1 + dist, 1);
        goto right;
    }
    
    dist2 = ask(1 + dist, 1);


    
    bottom:

    dist3 = ask(1, 1 + dist);

    if (bot || dist == dist2) { // the king is on the bottom
        ay = 1 + dist;
        ax = 1 + dist3;
        answer(min(n, ax), min(m, ay));
        return;
    }

    right:

    // otherwise, the king is on the right

    ax = 1 + dist;
    ay = 1 + dist2;

    answer(min(n, ax), min(m, ay));

}

signed main() { 
    cin.tie(0)->sync_with_stdio(false);

    int t; cin >> t;
    while (t--)
        solve();
}
