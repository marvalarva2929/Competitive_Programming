#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
#include <queue>
#define nl "\n"
#define vector2d vector<vector<pair<int,int>>>
using namespace std;

class Node {
    public:
    double score;
    int n;
    Node(int toN) { n = toN; }
    friend bool operator<(const Node & x, const Node & y) {
        return x.score > y.score;
    }
};



class Dijkstra {
    private:

    vector2d main_adjList;
    public: 
    Dijkstra(vector2d adjList) {
        main_adjList = adjList;
    }


    vector<int> shortest_paths(int v) {
        priority_queue<Node> nextNode;
        cout << "priority queue worked" << nl;
        vector<int> path(main_adjList.size());
        vector<bool> visited(main_adjList.size());
        Node init(v);
        init.score = 0;
        nextNode.push(init);
        Node curr = init;
        while (!nextNode.empty()) {    
            curr = nextNode.top();
            nextNode.pop();
            if (!visited[curr.n]) {
                visited[curr.n] = true;
                cout << "in loop " << curr.n << nl;
                path[curr.n] = curr.score;
                for (pair<int,int> edge : main_adjList[curr.n]) {
                    Node next(edge.first);
                    next.score = curr.score + edge.second;
                    nextNode.push(next);
                }
            }
        }
        cout << "returned" << nl;
        return path;
    }
};

int main() {
    ifstream fin("dijkstra.in");
    ofstream fout("dijkstra.out");
    vector<pair<int,int>> temp;
    int n, m, s;
    fin >> n >> m >> s;
    vector2d adjList(n + 1, temp);      
    // for (int i = 1; i <= m; i++) {
    //     string line;
    //     getline(fin, line, '\n');
    //     istringstream ss(line);
    //     int index;
    //     ss >> index;
    //     while(!ss.eof()) {
    //         int edgeTo, length;
    //         string l, ed;
    //         getline(ss, ed, ',');
    //         getline(ss, l, '\t');
    //         stringstream pair;
    //         if (!l.empty() && !ed.empty()) {
    //             length = stoi(l);
    //             edgeTo = stoi(ed);
    //         }
    //         adjList[i].push_back({edgeTo, length});
    //     }

    // }
    for (int i = 0; i < m; i++) {
        int x, y, w;
        fin >> x >> y >> w;
        adjList[x].push_back({y, w});
    }

    Dijkstra d(adjList);
    vector<int> path = d.shortest_paths(1);
    for (int i = 0; i < path.size(); i++) {
        fout << "the distance from " << i << " is " << path[i] << nl;
    }
    // while (true) {
    //     int x;
    //     cin >> x;
    //     cout << path[x] << nl;
    // }
}
