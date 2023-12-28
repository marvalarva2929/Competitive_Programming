#include <bits/stdc++.h>
#define int long long
#define pi pair<int, int>
#define ff first
#define ss second
#define nl " \n"

using namespace std;
const int mxn = 1e5;
int n, q;

void solve() {
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    vector<int> ta = a;
    
    while (q--) {
        //cout << q << nl; 
        a = ta;
        int k; cin >> k;
        int cur = 0;
        long long ans = 0;
        vector<int> na = a;
   
        for (int b = 60; b >= 0; b--) {
            int nd = 0;
            //cout << b << " : " << nl;

            for (int i = 0; i < n; i++) {
                if (!(((int)a[i] >> b) & 1)) {
                    nd += (((int)(a[i] >> b) + 1) << b) - a[i];
                    na[i] = (((int)(a[i] >> b) + 1) << b);  
                } else na[i] = a[i];
                if (nd > k) break;
                //cout << a[i] << nl[i == n - 1]; 
            }

            //cout << b << " : " << nd << " " << k << nl;
            
            //for (int x : na)
            //    cout << x << " ";
            //cout << nl;

            if (nd <= k) {
                //cout << " ------- " << b << nl;
                k -= nd;
                a = na;
                ans += ((int)1 << b); 
            }
        }

        cout << ans << nl;
    } 
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);
    
    int t = 1;
    while (t--)
        solve();
}
