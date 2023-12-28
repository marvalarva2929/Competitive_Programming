#include <bits/stdc++.h>
#define int long long
#define nl " \n"
#define pi pair<int, int>
#define ff first
#define ss second

using namespace std;
const int mxn = 5000;
int a[mxn], dp[mxn], cnt[mxn];

int solve() {
    int n; cin >> n;
    fill(cnt, cnt + n, 0);
    fill(dp, dp + n, INT_MAX);
    
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] < n) cnt[a[i]]++;
    }
    sort(a, a + n);
    int cur = -1;
    for (int i = n - 1; i >= 0; i--)
        if (!cnt[i]) cur = i;
    
    if (cur == -1) return 0;
    
    dp[0] = 0;
    for (int i = 1; i <= cur; i++)
        for (int j = 0; j < i; j++) {
            dp[i] = min(dp[i], dp[j] + ((cnt[j] - 1) * i) + j); 
        }
    
    return dp[cur];
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t; cin >> t;
    while (t--)
        cout << solve() << nl;
}
