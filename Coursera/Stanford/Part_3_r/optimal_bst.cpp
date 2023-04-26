#include <iostream>
#include <fstream>
#include <chrono>
#include <climits>
#define nl '\n'
using namespace std;

int main() {
    ifstream fin("bst.in");
    ofstream fout("bst.out");
    auto start = chrono::high_resolution_clock::now();
    int n;
    fin >> n;
    double freq[n + 1];
    freq[0] = 0;
    double dp[n + 1][n + 1]; // first and last index indicate range
    int root[n + 1][n + 1];
    for (int i = 1; i <= n; i++) {
        double f;
        fin >> f;
        // cout << f << nl;
        freq[i] = f + freq[i - 1]; 
    }
    for (int s = 0; s < n; s++) {
        for (int i = 1; i + s <= n; i++) {
            dp[i][i + s] = INT_MAX;
            double freq_sum = freq[i + s] - freq[i - 1];
            int minr;
            int lowR = i + s - 1 < i ? i : root[i][i + s - 1];
            int highR = i + s < i + 1 ? i + s : root[i + 1][i + s];
            for (int r = lowR; r <= highR; r++) {
                double a1, a2;
                if (r - 1 < i) {a1 = 0;}
                else a1 = dp[i][r - 1];
                if (i + s < r + 1) {a2 = 0;}
                else a2 = dp[r + 1][s + i];
                if (freq_sum + a1 + a2 < dp[i][i + s]) {
                    minr = r;
                }
                dp[i][i + s] = min(dp[i][i + s], freq_sum + a1 + a2);
            }
            root[i][i + s] = minr;
        }
    }
    auto end = chrono::high_resolution_clock::now();
    cout << "took: " << chrono::duration_cast<chrono::milliseconds>(end - start).count() << "ms" << nl;
    fout << dp[1][n] << nl;
}