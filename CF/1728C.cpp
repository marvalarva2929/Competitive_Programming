using namespace std;
#include <bits/stdc++.h>
#define int long long
#define nl '\n'

void solve() {
    int n; cin >> n;
    priority_queue<int> a, b;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        a.push(x);
    }
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        b.push(x);
    }

    int ans = 0;
    while(!a.empty() && !b.empty()) {
        int at = a.top(), bt = b.top();
        if (at == bt)   
            a.pop(), b.pop();
        else if (at > bt)
            a.pop(), a.push(log10(at) + 1), ans++;
        else if (bt > at)
            b.pop(), b.push(log10(bt) + 1), ans++;
    }                   

    cout << ans << nl;

    
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t; cin >> t;
    while (t--)
        solve();
}