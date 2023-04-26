#include <iostream>
#include <fstream>
#include <chrono>
#define nl '\n'
using namespace std;
int dp[101][10001];
int w[101];
int v[101];

auto start = chrono::high_resolution_clock::now();
int32_t main() {
    ifstream fin("knap.in");
    ofstream fout("knap.out");
    int32_t W;
    fin >> W;
    int32_t n;
    fin >> n;
    n = 100;
    W = 10001;
    for (int i = 1; i <= n; i++) {
        fin >> v[i] >> w[i];
    }
    for (int i = 0; i <= W; i++) dp[0][i] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= W; j++) {
            if(j > w[i]) {
                // cout << i << ": " << w[i] << nl;
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + v[i]);
            }
            else   
                dp[i][j] = dp[i - 1][j];
        }
    }
    fout << "The components in the knapsack are: " << nl;
    int j = W;
    for (int i = n; i > 0; i--) {
        if(dp[i - 1][j] >= (dp[i - 1][j - w[i]] + v[i])) {
            continue;
        } else if (j - w[i] > 0) {
            fout << "component " << i << " is in the sack, " << w[i] << ": " << v[i] << nl;
            j -= w[i];
        }
    }
    auto end = chrono::high_resolution_clock::now();
    cout << "took " << chrono::duration_cast<chrono::milliseconds>(end - start).count() << "ms" << nl;
    fout << "with a size of: " <<  dp[n][W] << nl;
}