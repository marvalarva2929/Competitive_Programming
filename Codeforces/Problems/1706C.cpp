using namespace std;
#include <bits/stdc++.h>
#define int long long
#define nl '\n'
#define MAX (int)2e5 + 10
int a[MAX] = {};

int cost(int i) {
    return max((int)0, max(a[i - 1], a[i + 1]) + 1 - a[i]);
}

void solve() {
    int n; cin >> n;



    for (int i = 0; i < n; i++)
        cin >> a[i];


        if (n % 2) {
        int ans = 0;
        for (int i = 1; i < n - 1; i+= 2)
            ans += cost(i);
        cout << ans << nl;
        return;
}

    int dp[n][2] = {};
    dp[1][1] = cost(2);
    dp[1][0] = cost(1);

    // while (true) {
    //     int x; cin >> x;
    //     cout << cost(x) << nl;
    // }

    for (int i = 3; i < n - 1; i+= 2) {
        dp[i][0] = dp[i - 2][0] + cost(i);
        dp[i][1] = min(dp[i - 2][1], dp[i - 2][0]) + cost(i + 1); 
    }

    // dp[0][0] = dp[0][1] = INT_MAX;
    // dp[n - 1][0] = dp[n - 1][1] = INT_MAX;

    

    cout << min(dp[n - 3][0], dp[n - 3][1]) << nl;
}


signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t; cin >> t;
    while (t--)
        solve();
}