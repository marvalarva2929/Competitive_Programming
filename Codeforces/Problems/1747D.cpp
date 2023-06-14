#include <bits/stdc++.h>
#define int long long
#define nl " \n"

using namespace std;

const int mxn = 3e5;
int a[mxn + 1], b[mxn + 1], c[mxn + 1], pref[mxn + 1];
unordered_map<int, int> last[2];

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int n, q; cin >> n >> q;
    fill(c + 1, c + n + 1, INT_MAX);

    for (int i = 0; i < n; i++)
        cin >> a[i + 1],
        pref[i + 1] = pref[i] + a[i + 1];

    for (int i = 1; i <= n; i++)
        b[i] = b[i - 1] ^ a[i];

    for (int i = n; i > 0; i--)
        c[i] = last[i % 2][b[i - 1]],
        last[i % 2][b[i]] = i;

    for (int i = 0; i < q; i++) {
        int l, r; cin >> l >> r; 
        
        if (b[l - 1] != b[r]) { cout << -1 << nl; continue; }
        if (pref[r] - pref[l - 1] == 0) { cout << 0 << nl; continue; }
        if ((r - l + 1) % 2 == 1) { cout << 1 << nl; continue; }
        int idx = c[l];
        if (a[l] == 0 || a[r] == 0) { cout << 1 << nl; continue; }
        if (idx == 0 || idx > r) { cout << -1 << nl; continue; }
        cout << 2 << nl;
        
    } 
}
