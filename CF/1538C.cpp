#include <iostream>
#include <climits>
#include <algorithm>
#include <set>
#include <vector>
#define nl '\n'
#define int long long
using namespace std;

int_fast32_t main() {
    int t;
    cin >> t;
    for (int q = 0; q < t; q++) {
        int n, l, r;
        cin >> n >> l >> r;
        int count = 0;
        vector<int> nums(n);
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
        }
        sort(nums.begin(), nums.end());
        nums.push_back(INT_MAX);
        for (int i = 0; i < n; i++) {
            int num = nums[i];
            if (num > r) {
                break;
            }
            int upper = r - num;
            int lower = l - num;
            // if (lower == num) lower++;
            count += upper_bound(nums.begin(), nums.end(), upper) - (nums.begin());
            count -= lower_bound(nums.begin(), nums.end(), lower) - (nums.begin());
            // cout << num << ": location of " << upper << " is " << one << " : " << "location of " << lower << " is " << two << nl;
            if (lower <= num && upper >= num) count--;


        }
        cout << count/2 << nl;
    }
}