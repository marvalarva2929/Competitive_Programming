using namespace std;
#include <bits/stdc++.h>
#define int long long
#define nl '\n'
#define MAX (int)2e5 + 10
bool a[2][MAX];
bool vis[2][MAX];

int m, visited = 0;


void solve() {
    cin >> m;
    int b = 0;
    memset(a, 0, sizeof(a));

    for (int i = 0; i < m; i++) {
        char c; cin >> c;
        a[0][i] = (c == 'B');
        b += a[0][i];
    }
    for (int i = 0; i < m; i++) {
        char c; cin >> c;
        a[1][i] = (c == 'B');
        b += a[1][i];
    }

    int start = -1;
    bool ors = 0;

    for (int i = 0; i < m; i++) 
        if (a[0][i] ^ a[1][i]) {
            start = i;
            ors = (a[0][i] ? 0 : 1);
            break;
        }
    
    if (start == -1) {
        cout << "YES" << nl;
    } else {
        int w = 0;
        int curr = start;
        int side = ors;
        bool right = false, left = false;
        while (curr < m) {
            for (curr; curr < m && a[side][curr] && !a[!side][curr]; curr++);
            for (int i = curr; i < m && (a[0][i] && a[1][i]); i++, curr++) w++;
            if (w&1) side = !side;
            // cout << w << " : " << curr << " " << side << nl;
            w = 0;            

            if (curr == m || !(a[0][curr] || a[1][curr])) {
                right = true;
                break;
            } else if (!a[side][curr] && a[!side][curr]) {
                right = false;
                break;
            }
        }

        w = 0;
        curr = start;
        side = ors;
        while (curr >= 0) {
            for (; curr >= 0 && a[side][curr] && !a[!side][curr]; curr--);
            for (; curr >= 0 && (a[0][curr] && a[1][curr]); curr--) w++;
            if (w&1) side = !side;
            // cout << curr << " : " << side << " : " << w << nl;
            w = 0;            
            if (curr == 0 || !(a[0][curr] || a[1][curr])) {
                left = true;
                break;
            } else if (!a[side][curr] && a[!side][curr]) {
                left = false;
                break;
            }
        }
        // cout << start << " : " << left << " : " << right << nl;
        cout << (right && left ? "YES" : "NO") << nl;
        

    }
    
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    int t; cin >> t;
    while (t--)
        solve();
}