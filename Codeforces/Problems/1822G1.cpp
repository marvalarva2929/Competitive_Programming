using namespace std;
#include <bits/stdc++.h>
#define int long long
#define nl '\n'

const int mxn = 2e5;
const int mxa = 1e6;

int a[mxn];
int cnt[mxa + 1];

void solve() {
    int n; cin >> n;
    int m = 0;
    int ans = 0;


    for (int i = 0; i < n; i++)
        cin >> a[i],
        m = max(m, a[i]),
        cnt[a[i]]++;

    for (int i = 0; i < n; i++)
        for (int j = 2; j <= (int)sqrt(m); j++)
            if (a[i] * j * j <= mxa)
                ans += cnt[a[i] * j] * cnt[a[i] * j * j];
    
    for (int i = 0; i < n; i++)
        ans += max((int)0, ((cnt[a[i]]) * (cnt[a[i]] - 1) * (cnt[a[i]] - 2))),
        cnt[a[i]] = 0;

    cout << ans << nl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t; cin >> t;
    while (t--)
        solve();
}