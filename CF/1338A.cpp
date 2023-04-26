#include <iostream>
#include <climits>
#include <vector>
#include <cmath>
#define nl '\n'
#define int long long
using namespace std;

int32_t main() {
    int t;
    cin >> t;
    for (int p = 0; p < t; p++) {
        int n, off = 0, m = INT_MIN, num = 0;
        cin >> n;
        vector<int> nums(n);
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
        }

        for (int i = 0; i < n; i++) {
            m = max(m, nums[i]);
            if (nums[i] < m) {
                off = max(m - nums[i], off);
                num++;
            }
        }
        if (off == 0) {
            cout << 0 << nl;
            continue;
        }
        int secs = 0;
        while (off > 0) {
            off -= (pow(2, secs++));
        }
        cout << secs << nl;
    }
}