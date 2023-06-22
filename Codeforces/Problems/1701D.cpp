#include <bits/stdc++.h>
#define int long long 
#define nl " \n"
#define pi pair<int, int>
#define ff first
#define ss second

using namespace std;

const int mxn = 5e5;
int a[mxn], ans[mxn];

void solve() {
    int n; cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    
    vector<pair<pi, int>> req;

    for (int i = 0; i < n; i++) {
        pair<pi, int> x = {{((i + 1) / (a[i] + 1)) + 1, a[i] ? ((i + 1) / a[i]) : n}, i}; 
        req.push_back(x); 
    }
    
    
    sort(req.begin(), req.end());

    priority_queue<pi> cur;
    int idx = 0; 
    for (int i = 1; i <= n; i++) {
        while (idx < req.size() && req[idx].ff.ff == i) {
            cur.push({-req[idx].ff.ss, req[idx].ss}); 
            idx++; 
        }
        
        ans[cur.top().ss] = i;
        cur.pop();  
    }
    
    for (int i = 0; i < n; i++)
        cout << ans[i] << nl[i == n-1];

}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t; cin >> t;
    while (t--)
        solve();
}
