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
#define f first
#define s second
#define print(x, y, z) for (int i = y; i <= z; i++) {cout << x[i] << " ";} cout << nl;

bool equal(vector<int> nums) {
    set<int> n;
    for (int num : nums)
        n.insert(num);
    return (n.size() == 1);
}

void solve() {
    int n, ans = 0;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    int iter = 0;
    while (!equal(nums)) {

    if (nums[0] > nums[1] || nums[n - 1] > nums[n - 2]) {
        cout << -1 << nl;
        return;
    }

    for (int i = 0; i < n - 2; i++) {
        int o = nums[i], t = nums[i + 1];
        if (o > t) continue;
        if (nums[i + 2] < t) {
            int diff = t - nums[i + 2];
            if (nums[i] < diff) {cout << -1 << nl; return; }
            nums[i] -= diff;
            nums[i + 1] -= diff;
            ans += 2 * diff;
        }
    }

    // cout << iter++ << nl;
    // print(nums, 0, n - 1);
    for (int i = n - 1; i > 1; i--) {
        int o = nums[i], t = nums[i - 1];
        if (o > t) continue;
        if (nums[i - 2] < t) {
            int diff = t - nums[i - 2];
            if (nums[i] < diff) {cout << -1 << nl; return; }
            nums[i] -= diff;
            nums[i - 1] -= diff;
            ans += 2 * diff;
        }
    }
        // cout << iter++ << nl;
    // print(nums, 0, n - 1);
    }
    
    cout << ans << nl;
    // print(nums, 0, n - 1);
}

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
} 