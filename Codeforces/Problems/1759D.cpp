using namespace std;
#include <bits/stdc++.h>
#define int long long
#define nl '\n'

void solve() {
    int n, k; cin >> n >> k;

    int t = 0, f = 0, l = 0; // divisors of 2, divisors of 5, leftover

    int nn = n;
    while (!(nn % 2) && nn)
        t++, nn /= 2;

    while (!(nn % 5) && nn)
        f++, nn /= 5;
    l = nn;

    int mul = 1;


    // cout << t << " " << f << " " << mul << nl;

    while (t != f && mul <= k)
        if (t < f)
            if (mul * 2 > k) break;
            else t++, mul *= 2;
        else if (t > f)
            if (mul * 5 > k) break;
            else  f++, mul *= 5;
    
    // cout << t << " " << f << " " << mul << nl;

    while (mul <= k)
        if (mul * 10 <= k)
            mul *= 10, t++, f++;
        else break;



    mul *= ((!t && !f) ? k : (k/mul));

    cout << n * mul << nl;

}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    int t; cin >> t;
    // cout << nl;
    while (t--)
        solve();
}