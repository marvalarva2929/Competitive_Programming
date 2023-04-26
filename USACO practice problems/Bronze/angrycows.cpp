#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <cmath>
using namespace std;
struct cow {double x, y, p; };
vector<cow> cows;
vector<int> adj[200];

int main() {
  ifstream fin("moocast.in");
  ofstream fout("moocast.out");
  
  int n, ans = 0;
  fin >> n;
  
  for (int i = 0; i < n; i++) {
    double x, y, p;
    fin >> x >> y >> p;
    cows.push_back({x,y,p});
  }

  for (int i = 0; i < n; i++) {
    int iterator = 0;
    for (int j = 0; j < n; j++) {
      double y = abs(cows[i].y - cows[j].y);
      double x = abs(cows[i].x - cows[j].x);
      if (sqrt(x + y) <= cows[i].p) {
        adj[i].push_back(j);
        iterator ++;
      }
    }
      ans = max(ans, iterator);

  }
  cout << ans - 1<< "\n";
}