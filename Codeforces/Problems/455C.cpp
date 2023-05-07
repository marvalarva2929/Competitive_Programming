#include <iostream>
#include <vector>
#include <map>
#define nl "\n"
#define ll long long
using namespace std;

int main() {
  int n, ma = 0;
  cin >> n;
  int nums[n];
  for (int i = 0; i < n; i++) {
    int a; cin >> a;
    nums[i] = a;
    ma = max(ma, a);
  }
  int freq[ma+1];
  ll dp[ma+1];
  for (int i = 0; i <= ma; i++) {
    dp[i] = freq[i] = 0;
  }
  for (int a : nums) freq[a]++;
  dp[0] = 0;
  dp[1] = freq[1];
  for (int i = 2; i <= ma; i++) {
    dp[i] = max(dp[i-1], dp[i-2]+ (ll) ((ll)  i * (ll) freq[i])); 
  }
  cout << dp[ma];
}