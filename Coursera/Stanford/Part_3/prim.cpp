#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <vector>
#include <set>
#include <fstream>
#define nl '\n'
#define weighted_adjacency_list vector<vector<pair<int,int>>> // adj.first = tail end, adj.second = edge weight
using namespace std;

class Prim {
    private:
        long long length = 0;
        weighted_adjacency_list main_AdjList;
        set<pair<int,int>> withinMST;
        struct Node {
            int n, score, prev;
            Node(int nu, int sc, int pre) {
                n = nu, score = sc, prev = pre;
            }
            friend bool operator<(const Node & a, const Node & b) {
                return a.score > b.score;
            }
        };
        struct Edge {
            int to, from, score;
            Edge(int v, int w, int s) {
                to = w, from = v, score = s;
            }
            friend bool operator<(const Edge & a, const Edge & b) {
                return a.score >= b.score;
            }
        };

    public:
        Prim(weighted_adjacency_list adjList) {
            main_AdjList = adjList;
            cout << main_AdjList.size() << nl;
            findMST();
        }

        void findMST() {
            priority_queue<Edge> nextEdge;
            int edges = 0;
            map<int, bool> visited;
            for (pair<int, int> edge : main_AdjList[2]) {
                Edge newEdge(2, edge.first, edge.second);
                nextEdge.push(newEdge);
            }
            visited[2] = true;
            cout << 'e' << nl;
            while(!nextEdge.empty()) {
                Edge curr = nextEdge.top();
                nextEdge.pop();

                // cout << curr.to << nl;
                if (!visited[curr.to]) {
                    edges++;
                    cout << withinMST.size() << ": " << curr.from << " ---> " << curr.to << ": " << curr.score << nl;
                    withinMST.insert({curr.from, curr.to});
                    length += curr.score;   
                    visited[curr.to] = true;
                    for (pair<int, int> edge : main_AdjList[curr.to]) {
                        if (!visited[edge.first]) {
                            Edge newEdge(curr.to, edge.first, edge.second);
                            // cout << curr.to << " ---> " << edge.first << ": " << edge.second << nl;
                            nextEdge.push(newEdge);
                        }

                    }
                }
            }
        }


        set<pair<int,int>> getMST() {
            return withinMST;
        }

        long long minLength() {
            return length;
        }
};

int main() {
    ifstream fin("edges.txt");
    ofstream fout("edges.out");
    vector<pair<int,int>> temp;
    int n, e;
    fin >> n >> e;
    weighted_adjacency_list adjList(n + 1, temp);
    while (!fin.eof()) {
        int v, w, l;
        fin >> v >> w >> l;
        adjList[v].push_back({w, l});
        adjList[w].push_back({v, l});
    }
    Prim prim(adjList);
    fout << prim.minLength() << nl;

}