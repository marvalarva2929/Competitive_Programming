/*
  ID: joshvig1
  LANG: C++
  TASK: gift1
*/

#include <bits/stdc++.h>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

std::vector<std::string> names;
int totals[10];

int indexOf(std::string name) {
  for (int i = 0; i < names.size(); i++) {
    if (name == names[i])
      return i;
  }
}

int main() {
  std::ifstream fin("gift1.in");
  std::ofstream fout("gift1.out");

  int NP;
  int counter = 0;

  fin >> NP;
  for (int i = 0; i < NP; i++) {
    std::string name;
    fin >> name;
    names.push_back(name);
  }

  for (int i = 0; i < NP; i++) {
    int ng, amt;
    std::string giver;
    fin >> giver >> amt >> ng;
    if (amt != 0 && ng != 0) {
      for (int j = 0; j < ng; j++) {
        std::string receiver;
        fin >> receiver;
        totals[indexOf(giver)] -= (amt / ng);
        totals[indexOf(receiver)] += (amt / ng);
      }
    }
  }

  for (std::string name : names) {
    fout << name << " " << totals[indexOf(name)] << std::endl;
  }
}
