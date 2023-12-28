#include <bits/stdc++.h>
#define int long long
#define pi pair<int, int>
#define ff first
#define ss second
#define nl " \n"

using namespace std;
const int mxn = 2e3;
int a[mxn];

int solve() {
    int n, k; cin >> n >> k;
    int mn = LLONG_MAX;

    for (int i = 0; i < n; i++)
        cin >> a[i], mn = min(mn, a[i]);
    
    if (k >= 3)  return 0;
    
    set<int> pos;
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            pos.insert(abs(a[j] - a[i]));
    
    if (k == 1) return min(*pos.begin(), mn);
    
    int ans = min(mn, *pos.begin());;
    for (int i = 0; i < n; i++) {
        auto it = pos.lower_bound(a[i]);
        if (it != pos.end()) ans = min(ans, abs(a[i] - *it));
        if (it != pos.begin()) ans = min(ans, abs(a[i] - *(--it))); 
    }
    
    return ans;
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t; cin >> t;
    while (t--)
        cout << solve() << nl;
}
