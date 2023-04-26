#include <vector>
#include <iostream>
#include <fstream>
#define MAX (int)1e3
#define nl '\n'
using namespace std;
int dp[MAX][2]; // first index represents which node, last index represents whether or not it is in the vertex cover

int main() {
    ifstream fin("vcov.in");
    ofstream fout("vcov.out");
    int n;
    fin >> n;
    vector<int> path(n + 1);
    for (int i = 1; i <= n; i++) {
        fin >> path[i];
        cout << i << ": " << path[i] << nl;
    }
    dp[1][1] = path[1];
    dp[2][0] = dp[1][1];
    dp[2][1] = dp[1][0] + path[2];

    for (int i = 3; i <= n; i++) {
        dp[i][0] = dp[i - 1][1];
        dp[i][1] = dp[i - 2][1] + path[i];
        cout << i << ": " << dp[i][0] << ": " << dp[i][1] << nl;
    }

    //NOTE: SAME AS MWIS! (almost)

    cout << min(dp[n][1], dp[n][0]) << nl;
}