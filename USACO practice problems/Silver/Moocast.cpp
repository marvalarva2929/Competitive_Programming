#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <cmath>
using namespace std;
struct cow {int x, y, p; };
vector<int> adj[200];
bool visited[200];

int cowsReached;

void DFS(int node){
	if(visited[node]){
		return;
	}
	cowsReached++;
	visited[node] = true;
	for(int connectedCow: adj[node]){
		DFS(connectedCow);
	}
}
int main() {
  ifstream fin("moocast.in");
  ofstream fout("moocast.out");
  int n;
  fin >> n;
  vector<cow> cows;
  
  for (int i = 0; i < n; i++) {
    int x, y, p;
    fin >> x >> y >> p;
    cows.push_back({x,y,p});
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      int y = cows[i].y - cows[j].y;
      int x = cows[i].x - cows[j].x;
      if (((x*x) + (y*y)) <= (cows[i].p * cows[i].p)) {
        adj[i].push_back(j);
      }
    }
  }
  int ans = 1;
  for (int i = 0; i < n; i++) {
    cowsReached = 0;
    fill(visited, visited+n, false);
    DFS(i);
    ans = max(ans, cowsReached);
  }
  fout << ans << "\n";
}
