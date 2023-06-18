#include <bits/stdc++.h>
#define int long long
#define nl '\n'
#define all(x) x.begin(), x.end()

using namespace std;

vector<int> divisors(int n) {
    vector<int> ret;
    for (int i = 1; i * i <= n; i++)
        if (!(n % i)) {
            ret.push_back(i);
            if (i * i != n) ret.push_back(n/i);
        }
    return ret;
}
void solve() {
    int a, b, c, d; cin >> a >> b >> c >> d;
    
    vector<int> fa = divisors(a);
    vector<int> fb = divisors(b);
    
    for (int f : fa) {
        for (int g : fb) {
            int aa = f * g;
            int bb = a * b / aa;

            int x = c / aa * aa, 
                y = d / bb * bb;

            if (a < x && x <= c && b < y && y <= d) {
                cout << x << " " << y << nl;
                return;
            }
        }    
    }

    cout << -1 << " " << -1 << nl;
}

signed main() { 
    cin.tie(0)->sync_with_stdio(false);

    int t; cin >> t; 
    while (t--)
        solve();
}
