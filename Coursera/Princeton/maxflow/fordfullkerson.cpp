using namespace std;
#include <bits/stdc++.h>
#include <string.h>
typedef long long ll;
typedef vector<int> vi;
typedef vector<pair<int,int>> vpi;
#define int long long
#define nl '\n'
#define sz(x) int(x.size())
#define print(x, y, z) for (int i = y; i <= z; i++) {cout << x[i] << " ";} cout << nl;
const int MAX = 500;

struct FlowEdge {

    int flow, capacity, v, w;

    FlowEdge(int f, int c, int head, int tail) {
        flow = f, capacity = c, v = head, w = tail;
    }

    int either() {
        return v;
    }

    int other(int x) {
        return (x == v ? w : v);
    }

    int residualCapacity(int x) {
        return (x == v ? (capacity - flow) : flow);
    }

    void addResidualCapacityTo(int x, int delta) {
        if (x == v) flow += delta;
        else flow -= delta;
        assert(residualCapacity(v) >= 0 && residualCapacity(w) >= 0);
    }
};

class FlowNetwork {
    private:

    vector<FlowEdge> adjList[MAX];

    public:

    FlowNetwork() {

    }

    
    void addEdge(FlowEdge e) {
        int v = e.either();
        int w = e.other(v);
        assert(v < MAX && w < MAX);
        adjList[v].push_back(e);
        adjList[w].push_back(e);
    }

    vector<FlowEdge> adjTo(int v) {
        return adjList[v];
    }
};

class FordFulkerson {
    public:

    FlowNetwork G;
    vector<FlowEdge> edgeTo;

    bool hasAugmentingPath(int s, int t) {
        edgeTo.clear();
        edgeTo.resize(MAX);
        queue<int> nextEdge;
        nextEdge.push(s);
        int curr;
        vector<int> visited(MAX);
        int prev = s;

        while (!nextEdge.empty()) {
            curr = nextEdge.front();
            nextEdge.pop();
            for (FlowEdge edge : G.adjTo(curr)) {
                int w = edge.other(curr);
                if (edge.residualCapacity(w) > 0 && !visited[w]) {
                    edgeTo[w] = edge;
                    visited[w] = true;
                    nextEdge.push(w);
                }
            }
        }
        return visited[t];
    }

    FordFulkerson(FlowNetwork N) {
        G = N;
    }

    int calculate(int s, int t) {
        int value = 0;
        while (hasAugmentingPath(s, t)) {
            int bottle = INT_MAX;
            for (int j = t; j != s; j = edgeTo[j].other(j))
                bottle = min(bottle, edgeTo[j].residualCapacity(j));
            
            for (int j = t; j != s; j = edgeTo[j].other(j))
                edgeTo[j].addResidualCapacityTo(j, bottle);

            value += bottle;
        }
        return value;
    }
};

int32_t main() {
    int n, s, t;
    cin >> n >> s >> t;
    FlowNetwork network;
    for (int i = 0; i < n; i++) {
        int x, y, l;
        cin >> x >> y >> l;
        FlowEdge edge(0, l, x, y);
        network.addEdge(edge);
    }
    FordFulkerson FF(network);
    cout << FF.calculate(s, t) << nl;
} 