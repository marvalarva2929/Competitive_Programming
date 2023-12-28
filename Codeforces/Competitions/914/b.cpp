#include <bits/stdc++.h>
#define int long long
#define pi pair<int, int>
#define ff first
#define ss second
#define nl " \n"

using namespace std;
const int mxn = 1e5;
pi a[mxn];
int pref[mxn];

void solve() {
    int n; cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i].ff, a[i].ss = i;
    sort(a, a + n);
    
    pref[0] = a[0].ff;
    for (int i = 1; i < n; i++)
        pref[i] = pref[i - 1] + a[i].ff;
    
    vector<int> ans(n);

    int cur = 1;
    for (int i = 0; i < n; i++) {
        int s = pref[i];
        while (cur < n && s >= a[cur].ff) s = pref[cur++];
        ans[a[i].ss] = cur - 1; 
    }
    
    for (int i = 0; i < n; i++)
        cout << ans[i] << nl[i == n -1];
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t; cin >> t;
    while (t--)
        solve();
}
