#include <bits/stdc++.h>
#define int long long
#define pi pair<int, int>
#define ff first
#define ss second
#define nl " \n"

using namespace std;

void solve() {
    int ta, b; cin >> ta >> b;
    
    int ans = INT_MAX;
   
    for (int i = 0; ((b >> i) > 0); i++) {
        int pref = b >> i;
        int a = ta;
        int res = 0;
       
        while (a > pref) {
            if (a & 1) a++, res++;
            a /= 2, res++;
        }

        res += pref - a;
        res += i;
        res += __builtin_popcount(b & ((1 << i) - 1));
        
        ans = min(ans, res); 
    } 
    
    cout << ans << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t; cin >> t;
    while (t--)
        solve();
}
