#include <bits/stdc++.h>
#define int long long
#define nl '\n'

using namespace std;

const int mxn = 1e5;
set<int> with[mxn + 2];
int a[mxn + 1];
int b[mxn + 1];

void solve() {
    int n; cin >> n;
    fill(with, with + n + 2, set<int>());

    for (int i = 1; i <= n; i++)
        cin >> a[i],
        with[a[i]].insert(i);
    
    int mode = with[n + 1].size() ? 1 : 0;
    int idx = 0, k;
    int cur;

    if (mode) k = -1, cur = n + 1;
    else k = n + 2, cur = 0;

    while (idx <= n) {
        if (mode) k = max(k, *(--with[cur].end()));
        else k = min(k, *(with[cur].begin()) - 1);
        
        //cout << mode << " " << cur << " : " << *with[cur].end() << nl;

        int ncur = -1;

        for (int x : with[cur])
            if (with[x].size()) {
                ncur = x;
                break;
            }

        for (int x : with[cur])
            if (x != ncur)
                b[++idx] = x;

        if (idx <= n) b[++idx] = ncur;
        
        cur = ncur;
        mode = !mode; 
    }

    cout << k << nl;
    for (int i = 1; i <= n; i++)
        cout << b[i] << " \n"[i == n];
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t; cin >> t;
    while (t--)
        solve();
}
