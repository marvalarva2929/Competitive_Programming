#include <bits/stdc++.h>
#define int long long
#define nl " \n"
#define pi pair<int, int>
#define ff first
#define ss second

using namespace std;
const int mxn = 2e5;
int a[mxn];

void solve() {
    int n, k; cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    if (a[0] != 1) {
        cout << 1 << nl;
        return;
    }
    
    int t = -1;
    for (int i = 1; i <= n; i++)
        if (a[i - 1] != i) {
            t = i - 1;
            break;
        }

    if (t == -1) { 
        cout << (n * k) + 1 << nl;
        return;
    }
    
    int cur = 1;
    int i = t;
    
    while (true) {
        
        if (i == n) {
            cout << cur + (t * k) << nl;
            return;
        }
    
        int mov = (a[i] - cur + t - 1) / t;
        //cout << i << " " << cur << " " << t << " : " <<  mov << " " << k << nl;
        if (k == 0) { cout << cur << nl; break; }
        if (mov > k) {
            cout << cur + (t * k) << nl;
            return; 
        } else {
            cur += ((mov - 1) * t);
            //cout << "-- " << cur << nl;
            k -= mov;

            int s = 0;
            int nc = 0;
            while (true) {
                int ad = (i == n) ? 0 : a[i] - max(cur, a[i - 1]) - 1;
                //cout << ad << " : " << i << " " << t  << nl;
                
                if ((s + ad) >= t || i == n) {
                    nc = a[i - 1] + (t - s);
                    break;
                } else {
                    s += ad;
                }
                i++;
            }
            t = nc - cur;
            cur = nc;
        } 
    }
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t; cin >> t;
    while (t--)
        solve();
}
