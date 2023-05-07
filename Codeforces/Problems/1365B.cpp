#include <iostream>
#include <vector>
#define nl '\n'

using namespace std;
vector <pair<int, int>> a; // pair.first = the number, pair.second = type

vector<int> merge(int low, int high, int n) {
    if (high - low == 1) return {a[low].first};

    vector<int> a1 = merge(low, (high+low)/2, n/2);
    vector<int> a2 = merge((high+low)/2, high, n - n/2);

    vector<int> c(n, 0);
    int i = 0, j = 0, k = 0;
    for (int q = 0; q < n; q++) {
      if (a[i].second != a[j].second) {
        i++;
        j++;
        continue;
      }
      if ((a1[i] < a2[j] || j >= a2.size()) && i < a1.size()) {
        c[k] = a1[i];
        k++;
        i++;
      } else if ((a2[j] <= a1[i] || i >= a1.size()) && j < a2.size()) {
        c[k] = a2[j];
        k++;
        j++;
      }
    }
    return c;
}

int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    int n;
    cin >> n;
    vector<int> nums;
    vector<int> types(2);
    for (int j = 0; j < n; j++) {
      int val;
      cin >> val;
      nums.push_back(val);
    }
    for (int j = 0; j < n; j++) {
      int type;
      cin >> type;
      types[type]++;
    }
    bool yes = true;
    for (int i = 1; i < n; i++) {
      if (nums[i] >= nums[i - 1]) {
        continue;
      }
      yes = false;
    }
    if (yes) {
      cout << "YES" << nl;
      continue;
    }
    if (n == types[0] || n == types[1]) {
      cout << "NO" << nl;
    } else {
      cout << "YES" << nl;
    }
  }
}