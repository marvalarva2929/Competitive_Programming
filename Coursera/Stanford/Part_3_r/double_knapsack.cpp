#include <iostream>
#include <fstream>
#include <set>
#include <chrono>
#define nl '\n'
#define MAX (int)1e3
using namespace std;
int w[MAX];
int v[MAX];
int dp[100][100][100]; //1st index represents amount of items, 2nd represents capacity of 2nd knapsack, 3rd represents capacity of 3rd knapsack

auto start = chrono::high_resolution_clock::now();
int main() {
    int n, w1, w2;
    set<int> knap1;
    set<int> knap2;
    ifstream fin("dknap.in");
    ofstream fout("dknap.out");
    fin >> n >> w1 >> w2;
    for (int i = 1; i <= n; i++) fin >> v[i] >> w[i];
    for (int i = 0; i <= w1; i++) 
        for (int j = 0; j <= w2; j++) 
            dp[0][i][j] = 0;
    
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= w1; j++) {
            for (int k = 0; k <= w2; k++) {
                int prevS1 = j >= w[i] ? dp[i - 1][j - w[i]][k] + v[i] : 0;
                int prevS2 = k >= w[i] ? dp[i - 1][j][k - w[i]] + v[i] : 0;
                dp[i][j][k] = max(dp[i - 1][j][k], max(prevS1, prevS2));
                // cout << i << ": " << j << ": " << k << ": " << dp[i][j][k] << " -- current item is, " << v[i] << ", " << w[i] << nl;
            }
        }
    } 
    auto end = chrono::high_resolution_clock::now();

        int j = w1, k = w2;
        for (int i = n; i > 0; i--) {
            int prevS1 = j >= w[i] ? dp[i - 1][j - w[i]][k] + v[i] : -1;
            int prevS2 = k >= w[i] ? dp[i - 1][j][k - w[i]] + v[i] : -1;
            if (dp[i][j][k] == dp[i - 1][j][k]) {
                continue;
            } else if (dp[i][j][k] == prevS1) {
                knap1.insert(i);
                j -= w[i];
            } else if(dp[i][j][k] == prevS2) {
                knap2.insert(i);
                k -= w[i];
            }
        }
        fout << "Knapsack 1 contains: {";
        for (int knap : knap1) {
            fout << knap << ", ";
        }
        fout << "} " << nl;
        fout << "Knapsack 2 contains: {";
        for (int knap : knap2) {
            fout << knap << ", ";
        }
        fout << "} " << nl;
    fout << "The maximum value is: " << dp[n][w1][w2];
    cout << "took " << chrono::duration_cast<chrono::milliseconds>(end - start).count() << "ms" << nl;
}