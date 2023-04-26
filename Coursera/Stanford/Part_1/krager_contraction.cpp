#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <random>
#include <vector>
#include <map>
#include <set>
#include <climits>
#include <bits/stdc++.h>
#include <random>
#define nl "\n"
#define vector2d vector<vector<int>>
using namespace std;
map<int, vector<int>> adj;

// IMPORTANT ::: THIS CODE DOESN'T REALLY WORK. IT FINDS MINIMUM CUTS, BUT NOT EFFICIENTLY.

std::random_device rd;  //Will be used to obtain a seed for the random number engine
std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
std::uniform_real_distribution<> distrib(0.0, 1.0);
int random(int min, int max) {
    return round((distrib(gen)) * (max - min)) + min;
}

vector<int> combine(int p, int q, vector<int> ab_of_p, vector<int> ab_of_q) {
    vector<int> ab;
    ab.reserve(ab_of_p.size() + ab_of_q.size());
    for (int i = 0; i < ab_of_p.size(); i++) 
        if (ab_of_p[i] != p && ab_of_p[i] != q) 
            ab.push_back(ab_of_p[i]);
    for (int i = 0; i < ab_of_q.size(); i++) 
        if (ab_of_q[i] != p && ab_of_q[i] != q) 
            ab.push_back(ab_of_q[i]);
    
    return ab;
}

int unique(map<int,vector<int>> check) {
    set<int> unique;
    for (pair<int,vector<int>> s : check) {
        for (int n : s.second) {
            unique.insert(n);
        }
    }
    return unique.size();
}

int krager(map<int, vector<int>> a) {
    map<int, vector<int>> adj = a;
    srand (time(NULL));
    while(unique(adj) > 2) {
        // STEP 1: find 2 nodes to delete
        int indexOfConnectTo = adj.lower_bound(random(1, adj.size()))->first;
        vector<int> connectTo = adj.at(indexOfConnectTo);      
        int baseIndexOfConnectFrom = random(0, connectTo.size() - 1);
        int indexOfConnectFrom = connectTo[baseIndexOfConnectFrom];
        vector<int> connectFrom = adj.at(indexOfConnectFrom);
        connectTo.erase(connectTo.begin() + (baseIndexOfConnectFrom));
        //STEP 2: replace all references to the "removed" node
        for (int n : adj[indexOfConnectFrom]) { // n is the index of each adjacent node to connectFrom
            for (int i = 0; i < adj[n].size(); i++) {
                if (adj[n][i] == indexOfConnectFrom && n != indexOfConnectTo) 
                    adj[n][i] = indexOfConnectTo;
            }
        }       
        //STEP 3: combine adjacency lists
        adj[indexOfConnectTo] = combine(indexOfConnectTo, indexOfConnectFrom, connectTo, connectFrom);
        adj.erase(indexOfConnectFrom);
    }

    for (pair<int,vector<int>> p : adj) {
        cout << p.first << ": ";
        for (int n : p.second) {
            cout << n << " ";
        }
        cout << nl;
    }
    cout << adj.begin()->second.size() << nl;
    return (adj.begin()->second.size());
}

int main() {
        srand (time(NULL));
    ifstream fin("krager.in");
    ofstream fout("krager.out");
    fstream f;
    f.open("krager.in");
    for (int i = 0; i < 200; i++) {
        stringstream ss;
        string adjlist;
        getline(f, adjlist, '\n');
        ss << adjlist;
        int j = 0;
        while (!(ss.eof())) {
            if (j == 0) ss >> j; 
            else {
                int m; ss >> m;
                adj[j].push_back(m);
            }
        }
    }
    int m = krager(adj);
    for (long long i = 0; i < 40000; i++) {
        cout << i << nl;
        m = min(m, krager(adj));
        cout << nl;
    }
    cout << m << nl;
}