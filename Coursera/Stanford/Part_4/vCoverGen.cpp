#include <iostream>
#include <vector>
#define MAX (int)1e3
#define nl '\n'
using namespace std;
int w[MAX];
vector<pair<int, int>> edges;

vector<int> cover(int k, vector<pair<int, int>> e) {
    
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> w[i];
    }
    for (int i = 0; i < m; i++) {
        int x, y, l;
        cin >> x >> y >> l;
        edges.push_back({x, y});
    }

}