#include <iostream>
using namespace std;

int main() {
  int a, b, c = 0;
  cin >> a >> b;
  int i = 0;
  while (a >= b) {
    c += b;
    a -= b;
    a++;
    }
  cout << a+c << "\n";
}