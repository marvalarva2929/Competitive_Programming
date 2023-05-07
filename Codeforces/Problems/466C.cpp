#include <vector>
#include <iostream>
#define int long long
#define nl '\n'
using namespace std;

int32_t main() {
    int n, t = 0;
    cin >> n;
    vector<int> nums(n + 1);
    vector<int> count(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> nums[i];
        t += nums[i];
    }
    if (t % 3 != 0) {
        cout << "0" << nl;
        return 0;
    }

    t /= 3;
    int ss = 0;
    for (int i = n; i >= 1; i--) {
        ss += nums[i];
        if (ss == t) count[i] = 1;
    }
    for (int i = n - 1; i >= 1; i--) {
        count[i] += count[i + 1];
    }
    int ans = 0;
    ss = 0;
    for (int i = 1; i <= n - 2; i++) {
        ss += nums[i];
        if (ss == t) ans += count[i + 2];
    }
    cout << ans << nl;
    
}