using namespace std;
#include <bits/stdc++.h>
#define int long long
#define nl '\n'

void solve() {
    int n; cin >> n;
    int a[n] = {};
    unordered_map<int, int> cnt;
    set<int> all;
    for (int i = 0; i < n; i++)
        cin >> a[i], cnt[a[i]]++, all.insert(a[i]);

    int s = 0, t = 0;
    
    for (int i : all)
        if (cnt[i] == 1) s++;
        else if (cnt[i] >= 2) t++;

    cout << (t + ceil((double)s/2)) << nl;
    
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t; cin >> t;
    while (t--)
        solve();
}