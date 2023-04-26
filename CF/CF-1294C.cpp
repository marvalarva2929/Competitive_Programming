#include <iostream>
#include <set>
#define nl "\n"
#define ll long long
using namespace std;

int main() {
  int t;
  cin >> t;
  
  for (int l = 0; l < t; l++) {
    int n, a, b, c;
    cin >> n;
    set <int> used;
    for (int i = 2; i * i <= n; i++) {
      if (n % i == 0 && !used.count(i)) {
        used.insert(i);
        n /= i;
        break;
      }
    }
    for (int i = 2; i * i <= n; i++) {
      if (n % i == 0 && !used.count(i)) {
        used.insert(i);
        n /= i;
        break;
      }
    }
    if ((int)used.size() < 2 || used.count(n) || n == 1) {
      cout << "NO" << nl;
    } else {
      cout << "YES" << nl;
      used.insert(n);
      for (auto num : used) cout << num << " ";
      cout << nl;
    }
  }
}