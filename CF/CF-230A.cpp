#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  int n, s;
  cin >> s >> n;
  vector<pair<int, int>> a;  
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    a.push_back({x,y});
  }
  sort(a.begin(), a.end());
  for (int i = 0; i < n; i++) {
      if(s > a[i].first) {
        s += a[i].second;
      } else {
        cout << "NO" << "\n";
        return 0;
      }
  }
  cout << "YES" << "\n";
}