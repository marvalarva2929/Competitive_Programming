#include <bits/stdc++.h>
#define int long long
#define nl " \n"
#define pi pair<int, int>
#define ff first
#define ss second

using namespace std;
const int mxn = 100;
int a[mxn], g[50];

void solve() {
    int n; cin >> n;
    int s = 0;

    for (int i = 0; i < n; i++)
        cin >> a[i], s += a[i];
    
    int t = 0;
    for (int i = 0; i < 50; i++) {
        if (g[i] == s + 1) { t = i; break; };
        if (g[i] > s + 1) { cout << "NO" << nl; return; };
    }
     
    t -= 2;

    priority_queue<pi> p;
    for (int i = 0; i < n; i++)
        p.push({a[i], i});
    
    int last = -1;
    for (int i = t; i >= 0; i--) {
        if (p.size() == 0) { cout << "NO" << nl; return; };
        pi q = p.top();
        p.pop();
        
        if (q.ss == last) {
            pi tq = q;
            if (p.size() == 0) { cout << "NO" << nl; return; };
            q = p.top();
            p.pop();
            p.push(tq);
        }
        
        last = q.ss;
        q.ff -= g[i];

        if (q.ff < 0) { cout << "NO" << nl; return; }
        else if (q.ff > 0) p.push(q);
    }
    
    cout << (p.size() ? "NO" : "YES")<< nl;
    return;
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);
    
    g[0] = 1, g[1] = 1;
    for (int i = 2; i < 50; i++)
        g[i] = g[i - 1] + g[i - 2];

    int t; cin >> t;
    while (t--)
        solve();
}
