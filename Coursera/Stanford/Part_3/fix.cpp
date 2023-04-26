#include <iostream>
#include <unordered_map>
#include <vector>
#include <cmath>
#include <fstream>
#include <set>
#include <list>
#include <chrono>
#define nl '\n'
using namespace std;

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
    ifstream fin("clusterBig.txt");
    ofstream fout("clusterBig.out");
    int n, bits;
    //TODO: replace cin with fin
    fin >> n >> bits;

    unordered_map<int, bool> exists;
    set<pair<int, int>> distance1;
    set<pair<int, int>> distance2;
    int maxBit = 0;
    for (int j = bits - 1; j >= 0; j--) maxBit += pow(2, j);
    id.resize(maxBit+2);
    sz.resize(maxBit+2, 1);
    for (int i = 1; i <= id.size(); i++) 
        id[i] = i;
    for (int i = 0; i < n; i++) {
        int toInsert = 0;
        for (int j = bits - 1; j >= 0; j--) {
            int bit;
            fin >> bit;
            toInsert += bit * pow(2, j);
        }
        // if (exists.find(toInsert) != exists.end()) cout << "there are: " << duplicates++ << " duplicates" << nl;
        exists.insert({toInsert, true});
    }
    cout << exists.size() << nl;
    components = exists.size();
    auto start = chrono::high_resolution_clock::now();
    for (pair<int, bool> node : exists) {
        int leadBit = 1 << ((int) log2(node.first));
        // cout << node.first << ": " << leadBit << nl;
        for (int i = leadBit; i > 0; i = i >> 1) {
            // cout << (i >> 1) << nl;
            int dist1 = node.first ^ i;
            // cout << dist1 << nl;
            if (exists.find(dist1) != exists.end() && dist1 != node.first) distance1.insert({node.first, dist1});
        }
    }
    for (pair<int, bool> node : exists) {
        int leadBit = 1 << ((int) log2(node.first));
        for (int i = leadBit; i > 0; i = i >> 1) {
            for (int j = leadBit; j > 0; j = j >> 1) {
                if (j == i) continue;
                int dist2 = node.first ^ i ^ j;
                if (exists.find(dist2) != exists.end() && dist2 != node.first) distance2.insert({node.first, dist2});
            }
        }
    }
    // for (pair<int, bool> node : exists) {
    //     int opposite = node.first ^ maxBit;
    //     int currBit = pow(2, (int) log2(opposite));
    //     for (int i = opposite; i > 0; i -= currBit) {
    //         currBit = pow(2, (int) log2(i));
    //         int dist1 = currBit + node.first;
    //         if (exists.find(dist1) != exists.end()) distance1.insert({node.first, dist1});
    //     }
    // }
    // for (pair<int, bool> node : exists) {
    //     int opposite = node.first ^ maxBit;
    //     int currBit = pow(2, (int) log2(opposite));
    //     for (int i = opposite; i > 0; i -= currBit) {
    //         currBit = pow(2, (int) log2(i));
    //         int currJBit = currBit;
    //         for (int j = i - currBit ; j > 0; j -= currJBit) {
    //             currJBit = pow(2, log2(j));
    //             int dist2 = currJBit + currBit + node.first;
    //             cout << node.first + currBit - currJBit << nl;
    //             if (exists.find(dist2) != exists.end()) distance2.insert({node.first, dist2});
    //             else if (exists.find(node.first + currBit - currJBit) != exists.end()) distance2.insert({node.first, node.first + currBit - currJBit});
    //         }
    //     }
    // }
    for (pair<int, int> edge : distance1) {
        // cout << edge.first << ": " << edge.second << nl;
        if (!isct(edge.first, edge.second)) {
            ct(edge.first, edge.second);
        }
    }
    cout << "distance 1 worked" << nl;
    for (pair<int, int> edge : distance2) {
        if (!isct(edge.first, edge.second)) {
            ct(edge.first, edge.second);
        }
    }
    fout << "you need " << components << " components" << nl;
    for (pair<int, int> edge : distance1) {
        fout << edge.first << " -> " << edge.second << ": " << 1 << nl;
    }
    for (pair<int, int> edge : distance2) {
        fout << edge.first << " -> " << edge.second << ": " << 2 << nl;
    }
    auto end = chrono::high_resolution_clock::now();
    cout << "took " << chrono::duration_cast<chrono::milliseconds>(end - start).count() << " ms" << nl;
}