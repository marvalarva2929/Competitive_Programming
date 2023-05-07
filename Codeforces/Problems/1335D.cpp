#include <iostream>
#include <map>
#define nl "\n"
using namespace std;

int main() {
  int t;
  map<char, int> cnvt = {
      {'1', 1}, {'2', 2}, {'3', 3}, {'4', 4}, {'5', 5},
      {'6', 6}, {'7', 7}, {'8', 8}, {'9', 9},
  };
  cin >> t;
  for (int tt = 0; tt < t; tt++) {
    int grid[9][9];
    for (int i = 0; i < 9; i++) {
      for (int j = 0; j < 9; j++) {
        char num;
        cin >> num;
        grid[i][j] = cnvt[num];
      }
    }
    int off = 3;
    for (int m = 0; m < 9; m += 1) {
      int j = ((m % 3) * 3) + (m / 3);
      grid[m][j] = (grid[m][j] % 9) + 1;
    }
    for (int i = 0; i < 9; i++) {
      for (int j = 0; j < 9; j++) {
        cout << grid[i][j];
      }
      cout << nl;
    }
  }
}