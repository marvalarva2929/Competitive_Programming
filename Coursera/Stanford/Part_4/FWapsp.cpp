#include <iostream>
#include <climits>
#include <fstream>
#include <list>
#define nl '\n'
#define MAX (int)100
#define int long long
using namespace std;
int dp[MAX][MAX][MAX];
int w[MAX][MAX];
int path[MAX][MAX];


list<int> reconstruct(int i, int j) {
    if (i == j) {
        return {i};
    } else if (path[i][j] == i || path[i][j] == j) {
        return {i, j};
    }
    cout << i << "  " << j << nl;
    list<int> one = reconstruct(i, path[i][j]);
    list<int> two = reconstruct(path[i][j], j);
    one.merge(two);
    return {one};
}

int32_t main() {
    ifstream cin("g1.txt");
    ofstream cout("g1out.txt");
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            dp[i][j][0] = abs(INT_MAX);

    for (int i = 0; i < m; i++) {
        int p, q, c;
        cin >> p >> q >> c;
        w[p][q] = c;
        dp[p][q][0] = c;
        path[p][q] = p;
    }
    for (int i = 1; i <= n; i++) {
        dp[i][i][0] = 0;
        path[i][i] = i;
    }


    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (dp[i][k][k - 1] == INT_MAX || dp[k][j][k - 1] == INT_MAX) {
                    dp[i][j][k] = dp[i][j][k - 1];
                } else {
                    dp[i][j][k] = min(dp[i][j][k - 1], dp[i][k][k - 1] + dp[k][j][k - 1]);
                    if (dp[i][k][k - 1] + dp[k][j][k - 1] < dp[i][j][k - 1]) {
                        path[i][j] = k;
                    }
                }
                std::cout << i << ": " << j << ": " << k << ": " << dp[i][j][k] << nl;
            }
        }
    }



    // while (true) {
    //     int x, y;
    //     cin >> x >> y;
    //     cout << "The shortest path between " << x << " and " << y << " is " << dp[x][y][n]  << nl;
    //     list<int> p = reconstruct(x, y);
    //     cout << "The path between " << x << " and " << y << " consists of ";
    //     for (int pa : p) cout << pa << " ";
    //     cout << nl;
    // }
    for (int i = 1; i <= n; i++) 
        for (int j = 1; j <= n; j++)
            cout << "The shortest path between " << i << " and " << j << " is " << dp[i][j][n] << nl;
}