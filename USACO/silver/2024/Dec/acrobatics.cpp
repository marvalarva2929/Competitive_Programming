#include <bits/stdc++.h>
#define int long long
#define pi pair<int, int>
#define ff first
#define ss second
#define nl " \n"

using namespace std;
const int mxn = 2e5;
pi a[mxn];

signed main() {
    int n, m, k; cin >> n >> m >> k;
    priority_queue<pi> pq;

    int s = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i].ff >> a[i].ss;
        s += a[i].ss;
    }
    sort(a, a + n, greater<pi>());
    pq.push({LLONG_MAX, m});
    
    int cur = 0;

    while (pq.size() && cur < n) {
        while (pq.size() && pq.top().ff >= a[cur].ff + k && a[cur].ss) {
            pi p = pq.top();
            pq.pop();

            int val = p.ff, amt = p.ss;

            int mn = min(amt, a[cur].ss);
        
            p.ss -= mn;
            a[cur].ss -= mn;

            if (p.ss) pq.push(p);
            pq.push({a[cur].ff, mn});
        }
        cur++;
    }
    
    for (int i = 0; i < n; i++)
        s -= a[i].ss;

    cout << s << endl;
}
