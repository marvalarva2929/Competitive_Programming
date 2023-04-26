using namespace std;
#include <bits/stdc++.h>
#define int long long
#define nl '\n'
#define MAX (int)2e5 + 10
int a[MAX];
int pref[MAX];

void solve() {
    int n; cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    pref[0] = a[0];
    for (int i = 1; i < n; i++)
        pref[i] = pref[i - 1] + a[i];

    int i = 0;
    int ans = 0;

    while (a[i] && i < n) ans += (pref[i] == 0), i++;

    unordered_map<int, int> cnt;

    while (i < n) {
        int j = i + 1;
        while (a[j] && j < n) j++;

        int mx = 0;
        for (int k = i; k < j; k++) 
            cnt[pref[k]]++, mx = max(mx, cnt[pref[k]]);

        ans += mx;
        i = j;
        cnt.clear();
    }
    cout << ans << nl;

}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t; cin >> t;
    while (t--)
        solve();
}