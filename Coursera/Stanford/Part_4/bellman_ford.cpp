#include <iostream>
#include <vector>
#include <chrono>
#include <fstream>
#include <climits>
#define MAX (int)1e3
#define nl '\n'
using namespace std;
vector<int> adj[MAX];
vector<int> inDegree[MAX];
int dp[2][MAX];
int w[MAX][MAX];
int path[2][MAX];

int main() {
    ifstream fin("bford.in");
    ofstream fout("bford.out");
    int n, m, s;
    fin >> n >> m >> s;
    // n is number of vertices, m is number of edges, s is the source vertex
    for (int i = 0; i < m; i++) {
        int p, q, we;
        fin >> p >> q >> we;
        w[p][q] = we;
        adj[p].push_back(q);
        inDegree[q].push_back(p);
    }
    vector<int> toRelax(n + 1, 0);
    auto start = chrono::high_resolution_clock::now();
    for (int i = 1; i <= n; i++) {
        dp[0][i] = abs(INT_MAX);
    }
    dp[0][s] = 0;
    toRelax[s] = false;
    for (int out : adj[s]) {
        toRelax[out] = 1;
        path[1][out] = s;
    }

    for (int m = 1; m < n; m++) {
        int i = 1;
        for (int j = 1; j <= n; j++) {
            if (toRelax[j] >= 1) {
                int relax = INT_MAX;
                int in;
                for (int smallest: inDegree[j]) {
                    if ((dp[i - 1][smallest] != INT_MAX)) {
                        if (dp[i - 1][smallest] + w[smallest][j] <= relax) {
                            relax = dp[i - 1][smallest] + w[smallest][j];
                            in = smallest;
                        }
                    }
                }
                if (relax >= dp[i - 1][j]) {
                    if (toRelax[j] <= 1) toRelax[j] = false;
                    else toRelax[j] = 1;
                    dp[i][j] = dp[i - 1][j];
                    path[i][j] = path[i - 1][j];
                } else {
                    toRelax[j] = 0;
                    for (int in : adj[j]) {
                        toRelax[in] = 2;
                    }
                    dp[i][j] = relax;
                    path[i][j] = in;
                }
            } else {
                dp[i][j] = dp[i - 1][j];
                path[i][j] = path[i - 1][j];
            }
        }
        for (int p = 1; p <= n; p++) {
            dp[0][p] = dp[1][p];
            path[0][p] = path[1][p];
        }
    }
    for (int i = 1; i <= n; i++) {
        fout << "the shortest path to " << i << " is " << dp[1][i] << ", from " << path[1][i] << nl;
    }
    auto end = chrono::high_resolution_clock::now();
    cout << "took " << chrono::duration_cast<chrono::milliseconds>(end - start).count() << "ms" << nl;
}