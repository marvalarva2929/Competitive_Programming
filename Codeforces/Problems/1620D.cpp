#include <bits/stdc++.h>
#define int long long
#define nl " \n"
#define pi pair<int, int>
#define ff first
#define ss second

using namespace std;
const int mxn = 100;
int a[mxn];

void solve() {
    int n; cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    
    int ans = INT_MAX;
    
    for (int one = 0; one < 3; one++)
        for (int two = 0; two < 3; two++) {
            int mx = 0;

            for (int i = 0; i < n; i++) {
                int mn = INT_MAX;
                
                for (int j = 0; j <= one; j++)
                    for (int k = 0; k <= two; k++) {
                        int b = j + k + k;
                        if (b <= a[i] && b % 3 == a[i] % 3) {
                            mn = min(mn, (a[i] - b)/3); 
                        }
                    }
                mx = max(mx, mn);
            }
            
            ans = min(ans, mx + one + two);
        }
        
    cout << ans << nl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t; cin >> t;
    while (t--)
        solve();
}
