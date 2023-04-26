#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <climits>
#define nl "\n"
using namespace std;
vector <int> bales;
vector <pair<int,int>> ranges;

bool check(int p, int q, int r) {
  for (int i = p+1; i < q; i++) {
    if (bales[i] - bales[i-1] > r) return 0;
  }
  return 1;
}

int main() {
  ifstream fin("angry.in");
  ofstream fout("angry.out");
  int n, k, ans = 0; fin >> n >> k;
  
  for (int i = 0; i < n; i++) { 
    int ni; fin >> ni;
    bales.push_back(ni);
  }
  sort(bales.begin(), bales.end());

  int high = 50000000;
  int low = 0;
  while (high != low) {
    int used = 0, last = 0, curr = 0, mid = (high+low)/2;
    while(last < n) {
      curr = last + 1;
      used++;
      while (curr < n && bales[curr] - bales[last] <= 2*mid) curr++;
      last = curr;
    }
    if (used <= k) high = mid;
    else low = mid+1;
  }
  fout << low << nl;
}