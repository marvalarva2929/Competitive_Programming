#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n, m, loc = 1;
  cin >> n >> m;
  vector<int> nums = {};

  for (int i = 0; i < m; i++) {
    int a;
    cin >> a;
    while ((loc+1) % n != a) loc++;
  }
  cout << loc << "\n";
}