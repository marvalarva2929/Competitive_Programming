#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <fstream>
#define nl '\n'
using namespace std;

struct Edge {
    int to, from, score;
    Edge(int t, int f, int s) {
        to = t, from = f, score = s;
    }
    friend bool operator<(const Edge & a, const Edge & b) {
        return a.score < b.score;
    }
};

vector<int> id;
vector<int> sz;

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
//   cout << p << ": " << q << "\n";
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
    ifstream fin("cluster.txt");
    ofstream fout("cluster.out");
    int k;
    cin >> k;
    int n;
    fin >> n;
    components = n;
    vector<Edge> edges;
    id.resize(n+2);
    sz.resize(n+2);
    vector<Edge> MST;

    for (int i = 1; i <= n; i++) {
        id[i] = i;
        sz[i] = 1;
    }
    while (!fin.eof()) {
        int one, two, score;
        fin >> one >> two >> score;
        Edge newEdge(one, two, score);
        edges.push_back(newEdge);
        // cout << newEdge.from << " --> " << newEdge.to << ": " << newEdge.score << nl;
    }

    sort(edges.begin(), edges.end());
    for (Edge curr : edges) {
        if (components <= k) {
            if (!isct(curr.to, curr.from)) {
            fout << "The minimum spacing is: " << curr.score << " from " << curr.from << " to " << curr.to << nl;
            break;
            } else {
                continue;
            }
        }
        if (!isct(curr.from, curr.to)) {
            ct(curr.from, curr.to);
            MST.push_back(curr);
        }
    }
    for (Edge edge : MST) {
        fout << edge.from << " --> " << edge.to << ": " << edge.score << nl;
    }
}