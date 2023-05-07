using namespace std;
#include <bits/stdc++.h>
#define int long long
#define nl '\n'

void solve() {
    int n; cin >> n;
    priority_queue<int, vector<int>, greater<int>> p;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        p.push(x);
    }

    int at = 0;
    int ans = 0;
    int curr = p.top();
    bool changed = true;

    while (p.size()) {
        while (p.top() <= at && p.size()) at++, curr = p.top(), p.pop(), changed = true;
        ans += changed;
        changed = false;

        // cout << at << " " << p.size() << nl;

        curr = p.top();
        while ((at <= curr || p.top() <= at) && p.size()) at++, curr = p.top(), p.pop(), changed = true;
        ans += changed;
        changed = false;

        // cout << at << " " << p.size() << nl;
    }

    cout << ans << nl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t; cin >> t;
    while (t--)
        solve();
}