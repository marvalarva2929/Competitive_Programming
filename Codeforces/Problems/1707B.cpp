#include <bits/stdc++.h>
#define int long long
#define nl " \n"

using namespace std;

const int mxn = 1e5;
int a[mxn];

void solve() {
    int n; cin >> n;
    int idx = 0;

    for (int i = 0; i < n; i++)
        cin >> a[i],
        idx += a[i] == 0;
    
    
    while (idx < n - 1) {
        if (idx) a[idx - 1] = a[idx];
        for (int i = idx; i < n - 1; i++)
            a[i] = a[i + 1] - a[i];
        if (idx) --idx;

        --n;
        sort(a + idx, a + n);
        while (a[idx] == 0) idx++;
    }
    
    cout << a[n - 1] << nl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t; cin >> t;
    while (t--)
        solve();
}
