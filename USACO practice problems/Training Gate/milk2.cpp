/*
  ID: joshvig1
  PROG: milk2
  LANG: C++
*/

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {
  ifstream fin = ifstream("milk2.in");
  ofstream fout = ofstream("milk2.out");

  struct time{
    int s;
    int e;
  };
  vector<time> times;
  
  int N, mint = 1000001, maxt = 0, maxCov = 0, maxNCov = 0, prevMaxCov = 0, prevMaxNCov = 0, unique = 0, prevID = 0;
  fin >> N;

  for (int i = 0; i < N; i++) {
    int ts, te;
    fin >> ts >> te;
    times.push_back({ts, te});  
    mint = min(mint, ts);
    maxt = max(maxt, te);
    }
  // cout << mint << endl << maxt << endl;
  int coverage[(maxt - mint)];
  for (int i = 0; i < (maxt - mint) + 1; i++) coverage[i] = 0;
  for (time t : times) {
    for (int i = (t.s - mint); i < (t.e - mint); i++ ) {
      coverage[i] = 1;
      // if(i == 199999) cout << 1 << endl;
    }
  }
  bool reset = true;
  for (time t : times) {
    // cout << t.s << endl;

    int id = t.s - mint;
    while (coverage[id] == 1)  {
      prevMaxCov += 1;
      maxCov = max(prevMaxCov, maxCov);
      id++;
    }
    prevMaxCov = 0;
    // cout << c << endl;
    // if(c == 1){
    //   maxNCov= max(maxNCov, prevMaxNCov);
    //   prevMaxNCov = 0;
    //   prevMaxCov++;
    // } else {
    //   cout << prevMaxNCov << endl;
    //   maxCov = max(maxCov, prevMaxCov);
    //   prevMaxCov = 0;
    //   prevMaxNCov++;
    // }
  }
  for (int c : coverage) {
    if (c == 0)  {
      prevMaxNCov += 1;
      maxNCov = max(prevMaxNCov, maxNCov);
    } else {
        prevMaxNCov = 0;
    }
  }
  // maxNCov = maxt - mint - unique;
  fout << maxCov << " " << maxNCov << endl;
}