#include <vector>
#include <iostream>
#include <map>
#include <algorithm>
#define nl '\n'
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int p = 0; p < t; p++) {
        int n, unique = 0;
        cin >> n;
        vector<int> nums(n);
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
        }
        bool ans = false;
        pair<int, int> ret = {0, 0};
        cout << 1 << " " << n << nl;
    }
}