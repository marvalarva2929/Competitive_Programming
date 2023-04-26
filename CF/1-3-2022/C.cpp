using namespace std;
#include <bits/stdc++.h>
#include <string.h>
typedef long long ll;
typedef vector<int> vi;
typedef vector<pair<int,int>> vpi;
#define pb push_back
#define int long long
#define nl '\n'
#define rsz resize
#define sz(x) int(x.size())
#define all(x) begin(x), end(x)
#define no "no"
#define yes "yes"
#define print(x, y, z) for (int i = y; i <= z; i++) {cout << x[i] << " ";} cout << nl;

void solve() {
    int n, m; cin >> n >> m;
    int a[n + 1] = {}, pref[n + 1] = {};
    for (int i = 0; i < n; i++)
        cin >> a[i], pref[i] = pref[i - 1] + a[i];

    int pm = pref[m];

    if (n == 1) {
        cout << 0 << nl;
        return;
    }

    int ans = 0;

    {
        priority_queue<int> p;
        int sum = 0;
        for (int i = m; i < n; i++) {
            sum += a[i];
            if (a[i] < 0) p.push(-a[i]);
            while (sum < 0) {
                sum += 2 * p.top();
                p.pop();
                ans++;
            }
        }
    }  
    {
        priority_queue<int, vector<int>, greater<int>> p;
        int sum = 0;
        for (int i = m - 1; i; i--) {
            sum += a[i];
            if (a[i] > 0) p.push(-a[i]);
            while (sum > 0) {
                sum += 2 * p.top();
                p.pop();
                ans++;
            }
        }
    }
    cout << ans << nl;
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(false);

    int t; cin >> t;
    while (t--)
        solve();
} 