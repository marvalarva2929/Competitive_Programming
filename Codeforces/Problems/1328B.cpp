#include <iostream>
#include <vector>
#define nl "\n"
using namespace std;

int main() {
  int t;
  cin >> t;
  for (int qq = 0; qq < t; qq++ ) {
    int n, k;
    cin >> n >> k;
    string word(n, 'a');
    for (int i = n-2; i >= 0; i--) {
      if (k <= n-1-i) {
        word[i] = 'b';
        word[n-k] = 'b';
        break;
      }
      k -= n-1-i;
    }
    cout << word << nl;
  }
}