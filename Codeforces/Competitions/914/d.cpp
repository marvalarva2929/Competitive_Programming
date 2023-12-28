#include <bits/stdc++.h>
#define int long long
#define pi pair<int, int>
#define ff first
#define ss second
#define nl " \n"

using namespace std;
const int mxn = 1e3;
int a[mxn+1], b[mxn+1];

bool solve() {
    int n; cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];
    a[n] = mxn + 1;
    b[n] = -1;

    for (int i = 0; i < n; i++)
        if (a[i] > b[i]) return 0;
    
    int ans = 1;
    for (int i = 1; i <= n; i++) {
        int l = 0, ib = 0, ia = 0;
        for (int j = 0; j <= n; j++) {

            if (b[j] < i || a[j] > i) {
                if (ib) ans &= ia;
                ia = ib = 0;
                l = j + 1;
            } else ia |= (a[j] == i), ib |= (b[j] == i); 
        
        } 
    }
    return ans;    
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t; cin >> t;
    while (t--)
        cout << (solve() ? "YES" : "NO") << nl;
}
