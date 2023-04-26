#include <iostream>
#include <cmath>
using namespace std;

int main() {
  int num, dig = 0;
  bool lucky = true;
  bool printed = false;
  cin >> num;
  while (true) {
    int n = (num / (int)  (pow(10, dig)) % 10);
    if (n == 0 && (num / (int)  (pow(10, dig)) < 10)) break;
    if (n != 7 && n != 4) lucky = false;
    dig++;
  }
  if (lucky) {
    cout << "YES" << "\n";
    printed = true;
  } else {
    if (dig == 1 && (num % 4 == 0 || num % 7 == 0)){ cout << "YES" << "\n"; printed = true;}
    if ((dig == 2 || dig == 3) && ((num % 4 == 0 || num % 7 == 0 || num % 47 == 0  || num % 74 == 0))) {cout << "YES" << "\n"; printed = true;}
    if (dig == 4) {cout << "YES" << "\n"; printed = true;}
  }

  if(!printed) cout << "NO" << "\n";
}