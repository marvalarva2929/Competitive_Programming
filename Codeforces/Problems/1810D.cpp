#include <bits/stdc++.h>
#define nl " \n"
#define pi pair<int, int>
#define ff first
#define ss second
#define int long long

using namespace std;

int turns(int a, int b, int h) {
    return ((max((int)0, h - a) + (a - b - 1)) / (a - b)) + 1;  
}

void solve() {
    int n; cin >> n;
    pi rng = {LLONG_MIN, LLONG_MAX};
    
    for (int i = 0; i < n; i++) {
        int q; cin >> q;
        if (q == 1) {
            int a, b, t; cin >> a >> b >> t; 
            int x = (t - 1) * (a - b);

            pi trng = {(b + 1) * (t > 1) + x, x + a};

            if (trng.ff > rng.ss || trng.ss < rng.ff) { cout << 0 << " "; continue; };
            cout << 1 << " ";

            rng.ff = max(rng.ff, trng.ff);
            rng.ss = min(rng.ss, trng.ss);

            //cout << i << " : " << rng.ff << " " << rng.ss << nl;
        } else if (q == 2) {
            int a, b; cin >> a >> b;
            if (rng.ff == LLONG_MIN) { cout << - 1<< nl; continue; }
            int l = turns(a, b, rng.ff),
                r = turns(a, b, rng.ss);

            if (l == r) cout << l << " ";
            else cout << -1 << " ";
        }
    }

    cout << nl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t; cin >> t;
    while (t--)
        solve();
}
