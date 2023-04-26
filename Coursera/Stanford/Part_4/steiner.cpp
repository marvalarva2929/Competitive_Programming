#include <iostream>
#include <vector>
#include <fstream>
#define nl '\n'
using namespace std;

int main() {
    ifstream fin("steiner.in");
    ofstream fout("steiner.out");
    int n, m, t;
    fin >> n >> m >> t;
    vector<int> terminals(t + 1);
    vector<pair<int, int>> temp;
    vector<vector<pair<int, int>>> adj(n + 1, temp);
    for (int i = 0; i < t; i++) 
        fin >> terminals[i];
    
    for (int i = 0; i < m; i++) {
        int x, y, l;
        cin >> x >> y >> l;
        adj[x].push_back({y, l});
    }
    
    
}