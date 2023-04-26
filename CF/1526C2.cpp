using namespace std;
#include <bits/stdc++.h>
#define int long long
#define nl '\n'

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int n; cin >> n;
    int a[n] = {};
    priority_queue<int, vector<int>, greater<int>> p;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    
    int curHealth = 0;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (curHealth + a[i] >= 0) {
            curHealth += a[i];
            ans++;
            p.push(a[i]);
        } else if (p.size() && p.top() < a[i]) {
            curHealth -= p.top();
            p.pop();
            curHealth += a[i];
            p.push(a[i]);
        }
    }
    cout << ans << nl;
}