#include <bits/stdc++.h>
#define int long long
#define nl " \n"
#define pi pair<int, int>
#define ff first
#define ss second

using namespace std;

const int mxn = 2e5;
int a[mxn], pref[mxn+1];
pi with[9];

void solve() {
    string s; cin >> s;
    int n = s.size();
    int w, m; cin >> w >> m;
    
    for (int i = 0; i < 9; i++)
        with[i] = {0, 0};

    for (int i = 0; i < n; i++)
        pref[i + 1] = pref[i] + (s[i] - '0');
    
    for (int i = 0; i <= n - w; i++) {
        int sum = pref[i + w] - pref[i];
        sum %= 9;
        if (!with[sum].ff) with[sum].ff = i + 1;
        else if (!with[sum].ss) with[sum].ss = i + 1; 
    }

    while (m--) {
        int l, r, k; cin >> l >> r >> k;
        int sum = pref[r] - pref[l - 1];
        pi ans = {INT_MAX, INT_MAX};
        
        for (int i = 0; i < 9; i++)
            if (with[i].ff)
                for (int j = 0; j < 9; j++)
                    if (with[j].ff)
                        if (((i * sum) + j) % 9 == k) {
                            if (i == j) {
                                if (!with[i].ss) continue; 
                                ans = min(ans, {with[i].ff, with[i].ss});
                            } else ans = min(ans, {with[i].ff, with[j].ff});
                        } 
        if (ans.ff == INT_MAX || ans.ss == INT_MAX)
            cout << -1 << " " << -1 << nl;
        else cout << ans.ff << " " << ans.ss << nl; 
    }
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t = 1; cin >> t; 
    while (t--)
        solve();
}

