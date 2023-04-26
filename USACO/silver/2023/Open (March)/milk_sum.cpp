using namespace std;
#include <bits/stdc++.h>
#define int long long
#define nl '\n'

const int mxn = 1.5e5 + 1;
int a[mxn];
multiset<int> aa;
int b[mxn]; // sorted a
int t[mxn]; // sorted indeces of a
int _t[mxn];
int pref[mxn]; // prefix sums
int n, q;

signed main() {
    cin.tie(0)->sync_with_stdio(false);
    cin >> n;
    iota(t, t + n + 1, 0);

    for (int i = 1; i <= n; i++)
        cin >> a[i],
        b[i] = a[i],
        aa.insert(a[i]);
    cin >> q;

    sort(b + 1, b + n + 1);
    sort(t + 1, t + n + 1, [](const int & x, const int & y) -> bool {
        return a[x] < a[y];
    });
    
    for (int i = 1; i <= n; i++)    
        _t[t[i]] = i;

    int ans = 0;
    for (int i = 1; i <= n; i++)
        ans += i * b[i];

    // cout << ans << nl;

    for (int i = 1; i <= n; i++)
        pref[i] = pref[i - 1] + b[i];

    while (q--) {
        int i, j; cin >> i >> j;

        int nw = lower_bound(b + 1, b + n + 1, j) - b,
            ol = _t[i];

        if (nw > ol) nw--;
        
        // cout << ol << " " << nw << nl;

        int new_ans = ans;

        if (nw < ol) { // the number moves to the left
            new_ans += pref[ol - 1] - pref[nw - 1];
        } else if (nw > ol) { // the number moves to the right
            new_ans -= pref[nw] - pref[ol];
        }

        cout << (new_ans + (nw * j) - (ol * a[i])) << nl;
    }
}