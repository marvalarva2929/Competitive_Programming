#include <bits/stdc++.h>
#define int long long
#define nl " \n"
#define pi pair<int, int>
#define ff first
#define ss second

using namespace std;
const int mxn = 1e3;

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int n; cin >> n;
    double p; cin >> p;
    
    double c = n * (n - 1) * (n - 2);

    for (int t = n; t >= 0; t--) {
    
        double p2 = 
            ((2.0 * (n - t) * (n - t - 1.0) * (n + t + t - 2.0)) + 
             (3.0 * (n - t) * t * (t - 1.0))) 
            / (2.0 * n * (n - 1.0) * (n - 2.0));
        
        if (p2 >= p) {
            cout << n - t << nl;
            return 0;
        }
    }
}
