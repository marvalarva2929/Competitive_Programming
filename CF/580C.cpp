#include <iostream>
#include <vector>
#include <map>
#define nl '\n'
#define MAX (int) 1e6
using namespace std;
vector<int> adj[MAX];
map<int, bool> visited;
map<int, bool> hasCat;
int mCat;
int count = 0;

void dfs(int s, int cats) {
    if (!visited[s] && cats <= mCat) {
        visited[s] = true;
        if (adj[s].size() <= 1 && s != 1) {
            count++;
            return;
        }
        for (int next : adj[s]) {
            int cat = (cats * hasCat[next]) + hasCat[next];
            dfs(next, cat);
        }
    }
}

int main() {
    int n;
    cin >> n >> mCat;
    for (int i = 1; i <= n; i++) cin >> hasCat[i];
    for (int i = 1; i < n; i++) {
        int t, w;
        cin >> t >> w;
        adj[t].push_back(w);
        adj[w].push_back(t);
    }
    dfs(1, hasCat[1]);
    cout << count << nl;
}