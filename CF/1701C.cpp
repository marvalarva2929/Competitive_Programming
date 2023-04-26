using namespace std;
#include <bits/stdc++.h>
#define int long long
#define nl '\n'
#define MAX (int)2e5 + 10
int a[MAX];
int cnt[MAX];
int m, n;

bool can(int t) {
    int canComplete = 0;
    // cout << t << nl;
    for (int i = 1; i <= n; i++) {
        // cout << '\t' << i << " :" << cnt[i] << nl;
        int ones = min(t, cnt[i]);
        int rest = (t - ones)/2;
        canComplete += ones + rest;
    }
    // cout << canComplete << nl;

    return canComplete >= m;
}

void solve() {
    cin >> n >> m;
    fill(cnt, cnt + n + 1, 0);

    for (int i = 0; i < m; i++)
        cin >> a[i], cnt[a[i]]++;

    int l = 1, r = m * 2;
    while (l < r) {
        int m = (l + r) >> 1;
        if (can(m))
            r = m;
        else l = m + 1;
    }
    cout << l << nl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t; cin >> t;
    while (t--)
        solve();
}