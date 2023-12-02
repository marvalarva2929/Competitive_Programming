#include <bits/stdc++.h>
#define int long long
#define nl " \n"
#define pi pair<int, int>
#define ff first
#define ss second

using namespace std;
const int mxn = 8e4, mxa = 1e5;
int a[mxn], len[mxa+1], cnt[mxa + 1], d[mxa + 1];

void solve() {
    int n, ans = 0; cin >> n;
    memset(len, 0, sizeof len);
    memset(cnt, 0, sizeof cnt);
    memset(d, 0, sizeof d);

    for (int i = 0; i < n; i++)
        cin >> a[i];
    
    sort(a, a + n);
    for (int i = 0; i < n; i++)
        ans += cnt[a[i]] * (n - i - 1) * a[i], len[a[i]] += n - i - 1, cnt[a[i]]++;

    for (int i = mxa; i; i--) {
        int s = 0; 
        for (int j = i; j <= mxa; j += i) 
            d[i] -= d[j], d[i] += s * len[j], s += cnt[j]; 
    }

    for (int i = 1; i <= mxa; i++)
        ans += i * d[i];
    
    cout << ans << nl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t; cin >> t;
    while (t--)
        solve();
}
