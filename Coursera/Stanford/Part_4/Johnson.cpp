#include <climits>
#include <fstream>
#include <chrono>
#include <iostream>
#include <queue>
#include <vector>
#define nl '\n'
#define int long long
#define MAX (int)1e3 + 10
#define vector2d vector<vector<pair<int,int>>>
using namespace std;
int w[MAX][MAX];

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
                path[curr.n] = curr.score;
                for (pair<int,int> edge : main_adjList[curr.n]) {
                    Node next(edge.first);
                    next.score = curr.score + edge.second;
                    nextNode.push(next);
                }
            }
        }
        return path;
    }
};


int32_t main() {
    auto start = chrono::high_resolution_clock::now();
    string filename;
    // std::cin >> filename;
    ifstream cin("g3.txt");
    ofstream cout("g1out.txt");
    int n, m, s = 0;
    vector<int> temp;
    cin >> n >> m;
    vector<int> t2(n + 1);
    vector<bool> t1(n + 1, true);
    vector<vector<int>> dp(n + 2, t2);
    vector<vector<int>> inDegree(n + 1, temp);
    vector<vector<bool>> toRelax(2, t1);
    vector<vector<int>> adj(n + 1, temp);
    for (int i = 0; i < m; i++) {
        // cout << i << nl;
        int x, y, l;
        cin >> x >> y >> l;
        w[x][y] = l;
        inDegree[y].push_back(x);
        adj[x].push_back(y);
    }

    for (int i = 1; i <= n; i++) {
        dp[0][i] = INT_MAX;
        w[s][i] = 0;
        w[s][i] = 0;    
        inDegree[i].push_back(s);    
        dp[1][i] = 0;
    }
    dp[0][s] = 0;

//TODO:: CHECK FOR NEG CYCLES, OPTIMIZE BELLMANFORD

    for (int i = 1; i <= n + 1; i++) {
        // cout << i << nl;
        for (int j = 1; j <= n; j++) {
                int relax = INT_MAX, inn;
                for (int in : inDegree[j]) {
                    int hL = w[in][j];
                    if (dp[i - 1][in] != INT_MAX) {
                        if (dp[i - 1][in] + hL < relax) {
                            relax = dp[i - 1][in] + hL; 
                            inn = in;
                        }
                    }
                }   
                if (relax < dp[i - 1][j]) {
                    for (int a : adj[j]) {
                        toRelax[1][j] = true;
                    }
                    dp[i][j] = relax;
                } else {
                    toRelax[1][j] = false;
                    dp[i][j] = dp[i - 1][j];
                }
            }
    }

    std::cout << 'd' << nl;

    for (int i = 1; i <= n; i++) {
        if (dp[n][i] > dp[n + 1][i]) {
            cout << "Negative cycle detected" << nl;
            cout << " Node " << i << " was involved" << nl;
            cout << dp[n + 1][i] << ": " << dp[n][i] << nl;
            auto end = chrono::high_resolution_clock::now();
            std::cout << "took " << chrono::duration_cast<chrono::milliseconds>(end - start).count() << "ms" << nl;
            return 0;
        }
    }

    std::cout << 'e' << nl;

    vector<vector<int>> distance(n + 1);
    vector<pair<int, int>> t;
    vector2d e_star(n + 1, t);
    for (int j = 0; j <= n; j++) {
        for (int a : adj[j]) {
            e_star[j].push_back({a, w[j][a] + dp[n][j] - dp[n][a]});
        }
    }

    priority_queue<int, vector<int>, greater<int>> smallest;

    for (int i = 1; i <= n; i++) {
        Dijkstra d(e_star);
        distance[i] = d.shortest_paths(i);
        for (int j = 0; j <= n; j++) smallest.push(distance[i][j] - dp[n][i] + dp[n][j]);
    }

    cout << "The smallest distance is " << smallest.top() << nl;

    auto end = chrono::high_resolution_clock::now();
    std::cout << "took " << chrono::duration_cast<chrono::milliseconds>(end - start).count() << "ms" << nl;
}