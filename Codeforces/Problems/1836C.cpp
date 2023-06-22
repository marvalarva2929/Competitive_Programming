#include <bits/stdc++.h>
#define int long long
#define nl " \n"
#define pi pair<int, int>
#define ff first
#define ss second

using namespace std;

int power(int a, int b) {
    int ans = 1;
    while (b) {
        if (b&1)
            ans *= a;
        b >>= 1;
        a *= a;
    }

    return ans;
}

void solve() {
    int a, b, c, k; cin >> a >> b >> c >> k;

    int mna = power(10, a - 1), mxa = power(10, a) - 1;
    int mnb = power(10, b - 1), mxb = power(10, b) - 1; 
    int mnc = power(10, c - 1), mxc = power(10, c) - 1;
   
    pair<int, pi> abc;
    
    for (int i = mna; i <= mxa; i++) {
        int ta = i;
        
        int tmnb = max(mnb, mnc - i), tmxb = min(mxb, mxc - i);
        int ways = tmxb - tmnb + 1;

        if (tmxb < tmnb) continue; 

        if (k - ways <= 0) {
            int tb = tmnb + k - 1;
            cout << ta << " + " << tb << " = " << ta + tb << nl;
            return;
        } else k -= ways;
    }
    
    cout << -1 << nl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t; cin >> t;
    while (t--)
        solve();
}

