#include <iostream>
#include <fstream>
using namespace std;

int main() {
  int n, ans = 0;
  cin >> n;
  while (n > 0) {
    n = n&(n-1);
    ans++;
  }
  cout << ans << "\n";
}