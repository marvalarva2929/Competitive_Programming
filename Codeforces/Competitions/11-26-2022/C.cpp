#include <iostream>
#include <algorithm>
#include <vector>
#define nl '\n'
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        long long nums[n];
        for (long long i = 0; i < n; i++) cin >> nums[i];
        sort(nums, nums + n);
        // for (int num : nums) cout << num << ' ';
        if (nums[0] == nums[n - 1]) {
            cout << n/2 << nl;
            continue;
        }
        long long ans = 0;
        for (long long i = 0, r = 0; i < n; i = r = r + 1) {
            if (nums[i + 1] != nums[i]) {
                ans = max(ans, 1ll*(n - 1 - i)*(i + 1)); 
            }
        }


        cout << ans << nl;
    }   
}

