using namespace std;
#include <bits/stdc++.h>    
#define int long long
#define nl '\n'
#define MAX (int)pow(2, 17) + 10
int a[MAX];

void solve() {
    int l, r; cin >> l >> r;
    fill(a, a + r + 1, 0);

    for (int i = 0; i < r + 1; i++)
        cin >> a[i];

    int cnt[18] = {};
    int ans = 0;

    for (int i = 0; i < 18; i++)
        for (int j = 0; j <= r; j++)
            cnt[i] += ((a[j] >> i) & 1);

    for (int i = 0; i <= 17; i++)
        if ((r + 1) - cnt[i] < cnt[i]) ans += (1 << i);

    cout << ans << nl;
    
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t; cin >> t;
    while (t--)
        solve();
}