#include <bits/stdc++.h>
#define int long long
#define nl '\n'
#define pi pair<int, int>
#define ff first
#define ss second

using namespace std;

void solve() {
    int n; cin >> n;
    vector<vector<int>> a(n, vector<int>());
    vector<int> dp(n);
    map<int, vector<int>> with; 
    
    for (int i = 0; i < n; i++) {
        int mx = -1;
        int k; cin >> k;
        for (int j = 0; j < k; j++) {
            int x; cin >> x;
            if (x > mx) a[i].push_back(x), mx = x;
        }
    }

    for (int i = 0; i < n; i++)
        for (int x : a[i])
            with[x].push_back(i);

    int last = 0;
    for (auto &p : with) {
        int c = p.ff;
        int newlast = 0;

        for (int &i : p.ss) {
            if (c == a[i].back())
                dp[i] = max(dp[i] + 1, last + 1),
                newlast = max(newlast, dp[i]);
            else if (c == a[i].front())
                dp[i] = last + 1;
            else dp[i] = max(dp[i] + 1, last + 1);
        }

        last = max(last, newlast);
    }
    
    cout << *max_element(dp.begin(), dp.end()) << nl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t; cin >> t;
    while (t--)
        solve();
}
