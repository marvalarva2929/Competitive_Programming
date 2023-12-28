#include <bits/stdc++.h>
#define int long long
#define nl " \n"
#define pi pair<int, int>
#define ff first
#define ss second

using namespace std;

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int n, t; cin >> n >> t;
    vector<pi> ds(n);

    for (int i = 0; i < n; i++)
        cin >> ds[i].ff >> ds[i].ss;
    sort(ds.begin(), ds.end());
    ds.push_back({t + 1, 0});

    int cur = 0, ls = 0;
    int ans = 0;

    for (pi d : ds) {
        int days = d.ff - ls - 1; 
        int s = min(days, cur);
        //cout << s << nl; 
        cur -= s;
        ans += s;

        ls = d.ff;
        ans++;
        cur += d.ss - 1;   
    }
    
    cout << ans - 1 << endl;
}

