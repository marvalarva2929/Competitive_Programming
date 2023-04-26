#include <iostream>
#include <algorithm>
#include <queue>
#include <set>
#define nl '\n'
using namespace std;

int g(int a, int b)
{
  if (a == 0)
    return b;
  return g(b % a, a);
}

int gcd(vector<int> arr, int n) {
  int result = arr[0];
  for (int i = 1; i < n; i++) {
    result = g(arr[i], result);
    if(result == 1) {
    return 1;
    }
  }
  return result;
}

int main() {
    int t;
    cin >> t;
    for (int p = 0; p < t; p++) {
        int n;
        cin >> n;
        vector<int> nums(n);
        set<int> ans;
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
            ans.insert(nums[i]);
        }
        int gc = gcd(nums, n);
        int a = (nums[n - 1] / gc);
        cout << a << nl;
    }
}