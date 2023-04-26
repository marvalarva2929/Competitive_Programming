#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
  
vector<int> id;
vector<int> sz;
vector<int> adg[200000];

int components = 0;

int root (int i) {
    while (i != id[i]) {
        i = id[i];
        id[i] = id[id[i]];
    }
    return i;
}

bool isct(int p, int q) { return (root(p) == root(q));}

void ct(int p, int q) {
  // cout << p << ": " << q << "\n";
  if (!isct(p, q)){
    p = root(p);
    q = root(q);
    if (sz[p] >= sz[q]) {
        id[q] = root(p);
        sz[p] += sz[q];
    }
    else {
        id[p] = root(q);
        sz[q] += sz[p];
    }
    components--;
  } 
}

int main() {
  ifstream fin("closing.in");
  ofstream fout("closing.out");

  int n = 0, m = 0, ma = 0;
  fin >> n >> m;
  id.resize(n+2);
  sz.resize(n+2);

  int close[n+1];
  bool ans[n+1];
  vector<bool> visible(n+1);
  for (int i = 1; i <= n; i++) {
    id[i] = -1;
    sz[i] = 1;
  }
  // for (int id: id) cout << id << "\n";
  for (int i = 0; i < m; i++) {
    int p, q;
    fin >> p >> q;
    adg[p].push_back(q);
    adg[q].push_back(p);
  }

  for (int i = 1; i <= n; i++) { fin >> close[i]; }
  reverse(close + 1, close + n + 1);
  
  for (int i = 1; i <= n; i++) {
    components++;
    int x = close[i];
    id[x] = x;
    visible[x] = true;
    for (int a : adg[x]) {
      if(visible[a]) {
        ct(a, x);
        // cout << i << ": " <<a.first << ": " << a.second << "\n";
      }
    }
    // cout << i << ": " << components << "\n";
    ans[i] = (components == 1); 
  }
  reverse(ans + 1, ans + n + 1);
    
  for (int i = 1; i<=n; i++) ans[i] == 1 ? fout << "YES"<< "\n" : fout << "NO" << "\n";
}