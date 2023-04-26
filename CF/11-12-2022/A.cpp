#include <iostream>
#include <cmath>
#define nl '\n'
using namespace std;

int main() {
 int t;
 cin >> t;
 for (int i = 0; i < t; i++) {
     int n;
     cin >> n;
     n = n % 2 == 1 ? n /2 + 1 : n /2;
     cout << n << nl;
 }
}