#include <iostream>
#include <climits>
using namespace std;
#define nl "\n"
#define MIN -(int)1e9

int main() {
  int n, a, b, c;
  cin >> n >> a >> b >> c;
  int dp[n+1];
  dp[0] = 0;
  for (int i = 1; i <= n; i++) {
    dp[i] = 0;
    int sA = INT_MIN, sB = INT_MIN, sC = INT_MIN;
    if (i >= a) {
      sA = dp[i-a];
    }
    if (i >= b) {
      sB = dp[i-b];
    }
    if (i >= c) {
      sC = dp[i-c];
    }
    dp[i] = max(sA, max(sB, sC)) + 1;
  }
  cout << dp[n] << nl;
}