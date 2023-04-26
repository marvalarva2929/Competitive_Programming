/*
  ID: joshvig1
  LANG: C++
  TASK: beads
*/
#include <fstream>
#include <iostream>

using namespace std;

int main() {
  ifstream fin = ifstream("beads.in");
  ofstream fout = ofstream("beads.out");

  
  string beads;
  int n;
  fin >> n >> beads;
  n = n + n;
  beads = " " + beads + beads + " ";
  int lft[n+1][2];
  int rgt[n+1][2];

  lft[0][0] = lft[0][1] = 0;
  rgt[n+1][0] = rgt[n+1][1] = 0;

  for (int i = 1; i <= n; i++) { 
    char b = beads[i];
    if(b == 'r'){
      lft[i][0] = lft[i-1][0] + 1; 
      lft[i][1] = 0;
    }
    else if(b == 'b'){
      lft[i][1] = lft[i-1][1] + 1; 
      lft[i][0] = 0;
    }
    else if(b == 'w') {
      lft[i][0] = lft[i-1][0] + 1; 
      lft[i][1] = lft[i-1][1] + 1;
    };
  }

  for(int i = n; i >= 1; i--){
    char bead = beads[i];
    if(bead == 'r') {
      rgt[i][0] = rgt[i+1][0] + 1; 
      rgt[i][1] = 0;
    }
    else if(bead == 'b') { 
      rgt[i][1] = rgt[i+1][1] + 1; 
      rgt[i][0] = 0;
    }
    else if(bead == 'w') {
      rgt[i][0] = rgt[i+1][0] + 1; 
      rgt[i][1] = rgt[i+1][1] + 1;
    }
  }


  int ans = 0;
  for(int i = 1; i <= n; i++){
    ans = max(ans, max(lft[i][0], lft[i][1]) + max(rgt[i+1][0], rgt[i+1][1]));
    ans = min(ans, n/2);
  }
  fout << ans << endl;
}