#include <iostream>
#include <cmath>
#include <climits>
#define nl "\n"
using namespace std;

int main() {
  int t = 0;
  cin >> t;
  for (int q = 0; q < t; q++) {
    int n, k, ans;
    cin >> n >> k;
    ans = n;
    for (int i = 1; i*i <= n; i++) {
      if (n % i == 0) {
        if (i <= k) ans = min(ans, n/i);
        if (n/i <= k) ans = min(ans, i);
      }
    }
    cout << ans << nl;
  }
  
}