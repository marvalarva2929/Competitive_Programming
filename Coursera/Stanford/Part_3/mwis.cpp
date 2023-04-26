#include <iostream>
#include <fstream>
#define nl '\n'
using namespace std;

int main() {
    int n;
    ifstream fin("mwis.txt");
    ofstream fout("mwis.out");
    fin >> n;
    int dp[n];
    int w[n];
    cout << 'e' << nl;
    for (int i = 0; i < n; i++) fin >> w[i];
    dp[0] = 0;
    dp[1] = w[1];
    for (int i = 2; i < n; i++) {
        dp[i] = max(dp[i - 1], dp[i - 2] + w[i]);
    }
    cout << dp[n - 1] << nl;
}