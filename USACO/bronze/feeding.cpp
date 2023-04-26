using namespace std;
#include <bits/stdc++.h>
#define int long long
#define nl '\n'

void solve() {
    int n, k; cin >> n >> k;
    bool a[n] = {};
    int b[n] = {}; // 1 for G, 2 for H, 0 for nothing
    for (int i = 0; i < n; i++) {
        char c; cin >> c;
        a[i] = (c == 'G');
    }   

    int cnt = 0;

    int wg = -1, wh = -1;
    int g = n + k, h = n + k;
    for (int i = 0; i < n; i++, wg--, wh--) {
        if (a[i] && wg < 0) 
            g = min(g, i + k);
        else if (!a[i] && wh < 0) 
            h = min(h, i + k);
        

        // cout << i << " : " << g << " " << h << nl;

        if (i == g) 
            b[i] = 1, wg = k, g = n + k, cnt++;
        else if (i == h)
            b[i] = 2, wh = k, h = n + k, cnt++;
    }


    if (g < n + k && h < n + k) 
        b[n - 2] = 2, b[n - 1] = 1, cnt += 2;
    else if (g < n + k)
        if (!b[n -1]) b[n - 1] = 1, cnt++;
        else b[n - 2] = 1, cnt++;
    else if (h < n + k)
        if (!b[n - 1]) b[n - 1] = 2, cnt++;
        else b[n - 2] = 2, cnt++;

    cout << cnt << nl;
    for (int i : b)
        cout << (i == 2 ? 'H' : i == 1 ? 'G' : '.');
    cout << nl;
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    int t; cin >> t;
    while (t--)
        solve();
}