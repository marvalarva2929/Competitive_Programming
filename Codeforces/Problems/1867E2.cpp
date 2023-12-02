#include <bits/stdc++.h>
#define int long long
#define nl endl
#define pi pair<int, int>
#define ff first
#define ss second

using namespace std;
int n, k;

int query(int x) {
    int an;
    
    cout << "? " << x  + 1<< nl;
    cin >> an;
    
    return an;
}

void solve() {
    cin >> n >> k;
    int x = (n % k) / 2;
    
    int i = 0;
    int ans = 0;
    while (i < n) {
        if ((n - i) > k && (n - i) < k + k) {
            ans ^= query(i) ^ query(i + x) ^ query(i + x + x);
            break; 
        } else {
            ans ^= query(i);
        }
        i += k; 
    }
    cout << "! " << ans << nl;
}

signed main() {

    int t; cin >> t;
    while (t--)
        solve();
}
