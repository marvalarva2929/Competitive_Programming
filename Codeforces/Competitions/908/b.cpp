#include <bits/stdc++.h>
#define int long long
#define nl " \n"
#define pi pair<int, int>
#define ff first
#define ss second

using namespace std;
const int mxn = 100;
int a[mxn], b[mxn], cnt[mxn+1];

void solve() {
    int n; cin >> n;
    fill(cnt, cnt + 101, 0);
    fill(b, b + n, 0);

    for (int i = 0; i < n; i++)
        cin >> a[i], cnt[a[i]]++;
    
    int w = 0, t = 0;
    pi tt = {0, 0};
    int ww;
    for (int i = 1; i <= 100; i++)
        if (cnt[i] >= 2) {
            tt.ff = tt.ss;
            tt.ss = i;
        }
    
    if (tt.ff) {
        for (int i = 0; i < n; i++)
            if (a[i] == tt.ff) {
                b[i] = 2;
                break;
            }
        
        for (int i = 0; i < n; i++)
            if (a[i] == tt.ss) {
                b[i] = 3;
                break;
            }
    
        for (int i = 0; i < n; i++)
            cout << (b[i] ? b[i] : 1) << nl[i == n- 1];
    } else { cout << -1 << nl; }
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t; cin >> t;
    while (t--)
        solve();
}
