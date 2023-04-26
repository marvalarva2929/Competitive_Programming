#include <iostream>
#include <map>
using namespace std;

int main() {
  string word, after;
  map<char, int> lett = {
    {'a', 1},
    {'e', 1},
    {'i', 1},
    {'o', 1},
    {'u', 1},
    {'y', 1},
  };
  cin >> word;

  for (int i = 0; i < word.size(); i++) {
      char c = tolower(word[i]);
      if ((lett[c]) != 1) {
          after.push_back('.');
          after.push_back((c));
      }
  }

  cout << after << "\n";
}