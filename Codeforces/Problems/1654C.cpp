using namespace std;
#include <bits/stdc++.h>
#define int long long
#define nl '\n'

void solve() {
    int n; cin >> n;
    priority_queue<int> a, b;
    int s = 0;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        a.push(x);
        s += x;
    }

    b.push(s);
    while (a.size() && b.size()) {
        if (b.top() > a.top()) {
            int c = b.top(); b.pop();
            b.push(ceil((double)c/2)), b.push(c/2);
        } else if (b.top() == a.top()) {
            a.pop(), b.pop();
        } else if (b.top() < a.top()) {
            cout << "NO" << nl;
            return;
        }
    } 

    if (!a.size() && !b.size()) {
        cout << "YES" << nl;
        return;
    }
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t; cin >> t;
    while (t--)
        solve();
}