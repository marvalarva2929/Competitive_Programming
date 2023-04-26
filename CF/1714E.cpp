using namespace std;
#include <bits/stdc++.h>
#define int long long
#define nl '\n'

int next(int x) {
    return x + (x % 10);
}

void solve() {
    int n; cin >> n;
    int a[n] = {};
    bool fv = false;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        if (x % 5 == 0) 
            fv = true, x = next(x);
        a[i] = x;
    }


    
    if (fv && *min_element(a, a + n) != *max_element(a, a + n)) {
        cout << "No" << nl;
        return;
    } else if (fv) {
        cout << "Yes" << nl;
        return;
    }
    
    bool f2 = false, f1 = false;

    for (int i = 0; i < n; i++) {
        while ((a[i] % 10) != 2)
            a[i] = next(a[i]);

        f1 |= (a[i] % 20 == 2);
        f2 |= (a[i] % 20 == 12);
    }

    cout << (f2 && f1 ? "no" : "yes") << nl;
    
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t; cin >> t;
    while (t--)
        solve();
}