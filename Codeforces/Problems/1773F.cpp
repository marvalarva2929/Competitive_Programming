using namespace std;
#include <bits/stdc++.h>
#define nl '\n'
#define int long long

void solve() {
    int n, a, b; cin >> n >> a >> b;
    if (n == 1) {
        cout << (a == b) << nl;
        cout << a << ":" << b << nl;
        return;
    } else if (a + b <= n) {
        cout << n - (a + b) << nl;
        for (int i = 0; i < a; i++)
            cout << 1 << ":" << 0 << nl;
        for (int i = 0; i < b; i++)
            cout << 0 << ":" << 1 << nl;
        for (int i = 0; i < n - (a + b); i++) {
            cout << 0 << ":" << 0 << nl;
        }
        return;
    } else if (a + b > n) {
        cout << 0 << nl;
        if (!b) {

            int i = 0;
            while (i < n - 1 && a > 1)
                cout << 1 << ":" << 0 << nl, i++, a--;
            cout << a << ":" << 0 << nl;
            
        } else if (!a) {

            int i = 0;
            while (i < n - 1 && b > 1)
                cout << 0 << ":" << 1 << nl, i++, b--;
            cout << 0 << ":" << b << nl;

        } else {
            int i = 0;
            while (i < n - 2 && a) cout << 1 << ":" << 0 << nl, a--, i++;
            while (i < (n - 2 + (!a)) && b) cout << 0 << ":" << 1 << nl, b--, i++;
            if (a) cout << a << ":" << 0 << nl;
            if (b) cout << 0 << ":" << b << nl;
        }
    }   
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t = 1;
    while (t--)
        solve();
}