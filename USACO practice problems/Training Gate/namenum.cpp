/*
NAME: joshvig1
PROG: namenum
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <cmath>
using namespace std;
typedef long long l;
map<int, vector<string>> mp;
map<char, l> twotone = {
  {'A', 2}, {'B', 2}, {'C', 2}, {'D', 3}, {'E', 3}, {'F', 3}, {'G', 4}, {'H', 4},{'I', 4}, {'J', 5}, {'K', 5}, {'L', 5}, {'M', 6}, {'N', 6}, {'O', 6}, {'P', 7}, {'R', 7}, {'S', 7}, {'T', 8}, {'U', 8}, {'V', 8}, {'W', 9}, {'X', 9}, {'Y', 9},
};
vector<string> words;

int digitsOf(l p) {
  int digits = 0;
  while (p > 0) {
    p = floor(p/10);
    digits++;
    // cout << p << endl;
  }
  return digits;
}

int main() {
  ifstream fin("namenum.in");
  ifstream dict("dict.txt");
  ofstream fout("namenum.out");

  string word;
  vector<string> names;
  l n = 0;
  fin >> n;
  int num = 0;
  num = digitsOf(n);
  cout << num << "\n";
  while (dict >> word) mp[word.size()].push_back(word);
  names = mp[num];
  bool none = true;
  for (string name : names) {
    l let1, let2, test = 0;
    bool viable = false;
    for (int i = 0; i < num; i++) {
        let1 = floor((l) ( n / (pow(10, i))) % 10);   
        test = n / (pow(10, i));
        let2 = twotone[name[name.size() - i - 1]];
        if (let1 == let2) {
          viable = true;
        } else { 
          // cout << test << ": " << let2 << ": " << i << ": " << name << endl;
          viable = false;
          break;
        }
    }
    if (viable) {
      none = false;
      fout << name << "\n";
      }
  } 
  if (none) fout << "NONE" << "\n";
}