#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main() {
  int n;
  string ans;
  vector<string> teams;
  map <string,int> scores;
  cin >> n;

  for (int i = 0; i < n; i++) {
    string team;
    cin >> team;
    scores[team] += 1;
  }
  for (auto score : scores) {
    teams.push_back(score.first);
  }
  if (teams.size() > 1) {
     ans = (scores[teams[0]] > scores[teams[1]] ) ? teams[0] : teams[1];
  } else {
     ans = teams[0];
  }
  cout << ans << "\n";
}