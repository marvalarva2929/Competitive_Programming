#include <iostream>
#include <fstream>
#define nl '\n'
using namespace std;

int main() {
    int n;
    ifstream fin("mwis.txt");
    ofstream fout("mwis.out");
    fin >> n;
    int t;
    long long dp[n + 1];
    int w[n + 1];
    bool mwis[n + 1];
    cout << 'e' << nl;
    for (int i = 1; i <= n; i++) fin >> w[i];
    w[0] = 0;
    dp[0] = 0;
    dp[1] = w[1];
    for (int i = 2; i <= n; i++) {
        dp[i] = max(dp[i - 1], dp[i - 2] + w[i]);
    }
    for (int i = n; i >= 1; i--) {
        if (dp[i - 2] + w[i] > dp[i - 1]) mwis[i--] = true;
    }
    cout << mwis[1] << mwis[2] << mwis[3] << mwis[4] << mwis[17] << mwis[117] << mwis[517] << mwis[997] << nl;
}