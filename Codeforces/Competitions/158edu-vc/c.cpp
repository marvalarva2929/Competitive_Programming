#include <bits/stdc++.h>
#define int long long
#define nl " \n"
#define pi pair<int, int>
#define ff first
#define ss second

using namespace std;
const int mxn = 2e5;
int a[mxn];

int p2(int x) {
    int cnt = 0;
    while (x)
        x >>= 1, cnt++;
    return cnt;
}

void solve() {
    int n, b = 0; cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i], b = max(b, p2(a[i]));
    
    if (n == 1) { cout << 0 << nl; return; }

    int x = 0;
    for (int i = b - 1; i >= 0; i--) {
        
        bool o = 1, h = 0, e = 1;
        for (int j = 0; j < n; j++)
            o &= !((a[j] >> i) & 1),
            h |= !(a[j] & ((1 << i) - 1)) && !((a[j] >> i) & 1),
            e &= (a[j] >> i) & 1; 
        
        if (e) continue;
        if (o) {
            x += (1 << i); 
            for (int i = 0; i < n; i++)
                a[i] += x;
        } else if (!h) {
            x += (1 << i) - 1; 
            for (int i = 0; i < n; i++)
                a[i] += x;
        } else {
            cout << i + 1 << nl;
            if (i + 1 <= n) {
                cout << x << nl;
                for (int j = 0; j < i; j++) cout << 0 << nl;
            }
            return; 
        }
    }
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t; cin >> t;
    while (t--)
        solve();
}
