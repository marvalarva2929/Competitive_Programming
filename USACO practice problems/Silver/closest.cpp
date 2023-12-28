using namespace std;
#include <bits/stdc++.h>    
#define int long long
#define nl '\n'
#define pi pair<int, int>
#define pub push_back
const int mxn = 2e5 + 10;

pi a[mxn]; // The grassy patches
pi r[mxn]; // the ranges for each grassy patch
vector<int> b; // farmer Nhoj's Cow's
int n, m, k;

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    cin >> k >> m >> n;
    for (int i = 0; i < k; i++) {
        int p, t; cin >> p >> t;
        a[i] = {p, t};
    }    
    for (int i = 0; i < m; i++) {
        int x; cin >> x;
        b.pub(x);
    }
    sort(b.begin(), b.end());
    sort(a, a + k);

    // for (int i 

    for (int i = 0; i < k; i++) {
        int l = lower_bound(b.begin(), b.end(), a[i].first) - b.begin();
        int mn = LLONG_MIN, mx = LLONG_MAX;
        int delta = 0;
        if (l > 0)
            mn = max(mn, b[l - 1]), delta = abs(a[i].first - mn);
        if (l < m)
            mx = min(mx, b[l]), delta = min(delta, abs(a[i].first - mx));
        
        r[i] = {a[i].first - delta, a[i].first + delta};
    }

    priority_queue<int> pq;

    int currright = LLONG_MAX, currleft = LLONG_MIN;
    int curscore = 0;
    for (int i = 0; i < k; i++) {
        if (r[i].first < currright && r[i].first >= currleft) {
            curscore += a[i].second;
            currright = min(currright, r[i].second);
            currleft = max(currleft, r[i].first);
            // cout << i << nl;
        } else {
            // cout << i << ": " << currleft << " " << currright << " : "<< r[i].first << " " << r[i].second << nl;
            pq.push(curscore);
            currright = r[i].second;
            currleft = r[i].first;
            curscore = a[i].second;
        }
    }
    pq.push(curscore);
    int ans = 0;
    for (int i = 0; i < n && pq.size(); i++) {
        ans += pq.top();
        pq.pop();
    }
    cout << ans << nl;
}
