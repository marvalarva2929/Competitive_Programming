#include <bits/stdc++.h>
#define int long long
#define nl '\n'

using namespace std;
int n, k, g;

int math(int x) {
    int r = x % g;

    if (r >= (g + 1)/2) return -(g - r);
    else return r;
}

void solve() {
    cin >> n >> k >> g;

    int tar = (g % 2) ? g/2 : g/2 - 1;
    int div = (g % 2) ? g/2 + 1 : g/2;

    if (tar * n >= k * g) cout << k * g << nl;
    else {
        int left = (k * g) - (tar * n);
        int loss = tar - math(tar + left);
        cout << (tar * n) - loss << nl;
    }
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);
    
    int t; cin >> t;
    while (t--)
        solve();
}
