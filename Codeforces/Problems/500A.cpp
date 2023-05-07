#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
vector<int> adj[(long long) 3e4];
int a[(long long) 3e4];
int visited[(long long) 3e4];

void dfs(int node) {
  if (!visited[node]) {
    visited[node] = true;
    for(int i = 0; i < adj[node].size(); i++) {
      dfs(adj[node][i]);
    }
  } else {return;}
}

int main() {
  int n, t;
 
  cin >> n >> t;
  
  for (int i = 1; i < n; i++) {
    cin >> a[i];
  }

  for (int i = 1; i < n; i++) {
    adj[i].push_back(a[i]+i);
    visited[i] = false;
  }
  
  dfs(1);
  if(visited[t]) cout << "YES" << "\n";
  else cout << "NO" << "\n";
}