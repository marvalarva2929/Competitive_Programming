#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#define nl "\n"
#define ll long long
using namespace std;
vector<int> adj[(ll) 1e5];
int cats[(ll) 1e5];
ll ans = 0;
int m;
void dfs(int r, int pr, int c) {
  if (c > m) return;
  int isleaf = 1;
  // cout << r << ": " << c << ": " << isleaf << nl;
  for (int v = 0; v < adj[r].size(); v++) {
     if (adj[r][v] != pr) {
       isleaf = 0;
       dfs(adj[r][v], r, c + (cats[adj[r][v]] * cats[adj[r][v]]));
     } 
  }
  ans += isleaf;
}

int main() {
  int n;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> cats[i];
  }

  for (int i = 0; i < n-1; i++) {
    int p, q; cin >> p >> q;
    adj[p].push_back(q);
    adj[q].push_back(p);
  }

  dfs(1, 0, cats[1]);
  cout << ans << nl;
}