using namespace std;
#include <bits/stdc++.h>
#define int long long
#define nl '\n'

const int mxn = 1e5;
const int mxc = 18;

int a[mxn];
int ans[(1 << mxc)];
int n, c;

signed main() {
    cin.tie(0)->sync_with_stdio(false);
    cin >> c >> n;

    fill(ans, ans + (1 << mxc), c + 1);

    for (int i = 0; i < n; i++) {
        string t; cin >> t;
        int x = 0;
        for (int j = 0; j < c; j++)
            x += (t[j] == 'H') << j;
        a[i] = x;
        ans[x] = 0;
    }

    for (int i = 0; i < c; i++)
        for (int j = 0; j < (1 << c); j++)
            ans[j ^ (1 << i)] = min(ans[j ^ (1 << i)], ans[j] + 1);

    for (int i = 0; i < n; i++)
        cout << c - ans[(a[i] ^ ((1 << c) -1))] << nl;

}