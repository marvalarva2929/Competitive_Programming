using namespace std;
#include <bits/stdc++.h>    
#define int long long
#define nl '\n'
#define MAX (int)2e5 + 10
int a[MAX], b[MAX];
int n;

bool check(int x) {
    int less = 0;
    for (int i = 0; i < n; i++) { // x - less - 1 <= a[i] && less <= b[i]; x - 1 - a[i] <= less <= b[i]
        if (x - 1 - a[i] <= less && less <= b[i])
            less++;
    }
    return less >= x;
}

void solve() {
    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> a[i] >> b[i];

    int l = -1, r = n + 1;
    while (r - l > 1) {
        int m = (r + l) >> 1;
        if (check(m))
            l = m;
        else r = m;
    }
    cout << l << nl;
    return;
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t; cin >> t;
    while (t--)
        solve();
}