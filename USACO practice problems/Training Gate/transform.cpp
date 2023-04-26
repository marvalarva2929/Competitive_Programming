/*
  NAME: joshvig1
  PROG: transform
  LANG: C++
*/
#include <iostream>
#include <fstream>
#include <map>
#include <string>

using namespace std;

int main() {
  
  ifstream fin = ifstream("transform.in");
  ofstream fout = ofstream("transform.out");

  int n;
  fin >> n;
  
  char before[n][n];
  char after[n][n];
  bool one = true, two = true, three = true, four = true, five1 = true, five2 = true, five3 = true, six = true;
  
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++){
      fin >> before[i][j];
    }
  }
  
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++){
      fin >> after[i][j];
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++){
      bool comb1 = before[i][j] == after[j][i]; 
      bool comb2 = before[i][j] == after[n-1-i][j]; 
      bool comb3 = before[i][j] == after[n-1-j][n-1-i];
      if (one)   before[i][j] == after[j][n-1-i]       ?    one = true   :    one = false;
      if (two)   before[i][j] == after[n-1-i][n-1-j]   ?    two = true   :    two = false;
      if (three) before[i][j] == after[n-1-j][i]       ?  three = true   :  three = false;
      if (four)  before[i][j] == after[i][n-1-j]       ?   four = true   :   four = false;
      if (five1)  comb1                                ?  five1 = true   :  five1 = false;
      if (five2)  comb2                                ?  five2 = true   :  five2 = false;
      if (five3)  comb3                                ?  five3 = true   :  five3 = false;
      if (six)   before[i][j] == after[i][j]           ?    six = true   :    six = false;
    }
  }
  one ? 
    fout << 1 << endl : two ?
      fout << 2 << endl : three ?
        fout << 3 << endl : four ?
          fout << 4 << endl : five1 || five2 || five3 ?
            fout << 5 << endl : six ?
              fout << 6 << endl : fout << 7 << endl;
}