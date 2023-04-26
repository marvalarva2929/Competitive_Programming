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
#define max(x, y) (int)max((int)x, (int)y)
void solve() {
    int n, k; cin >> n >> k;
    vector<int> nums(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> nums[i];

    int i = max(1, n - (2 * k));
    int ans = INT_MIN;
    for (i; i <= n; i++)
        for (int j = i + 1; j <= n; j++) {
            ans = max(ans, (i * j) - (k * (nums[i] | nums[j])));
        }

    cout << ans << nl;
}

int32_t main() {
    int t; cin >> t;
    while (t--)
        solve();
} 