#include <iostream>
#include <fstream>
#include <algorithm>
#include <sstream>
#define nl '\n'
using namespace std;

int p(char a, char b) {
    return a == b ? 0 : 1;
}

int main() {
    ifstream fin("seq.in");
    ofstream fout("seq.out");
    string x, y;
    fin >> x >> y;
    int n = x.size();
    int m = y.size();
    int st = max(n, m);
    int sta = min(n, m);
    string xOptimal, yOptimal;
    int dp[n + 1][m + 1];
    for (int i = 0; i <= n; i++)
        dp[i][0] = i;
    for (int i = 0; i <= m; i++) 
        dp[0][i] = i;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <=m; j++) {
            dp[i][j] = min(dp[i - 1][j - 1] + p(x[i - 1], y[j - 1]), min(dp[i - 1][j] + 1, dp[i][j - 1] + 1));
        }
    }
    int i = n;
    int j = m;
    stringstream xO;
    stringstream yO;
    while (true) {
        cout << i << ": " << j << " -- " << dp[i][j] << nl;
        if (dp[i][j] == dp[i - 1][j - 1] + p(x[i - 1], y[j - 1])) {
            xO << x[i - 1];
            yO << y[j - 1];
            i--;
            j--;
        } else if (dp[i][j] == dp[i - 1][j] + 1) {
            xO << x[i - 1];
            yO << ' ';
            i--;
        } else if (dp[i][j] == dp[i][j - 1] + 1) {
            xO << ' ';
            yO << y[j - 1];
            j--;
        }
        if (i < 1) {
            while (j > 0) {
                yO << y[j-- - 1];
                xO << ' ';    
            }
            break;
        }
        if (j < 1) {
            while (i > 0) {
                 xO << x[i-- - 1];
                 yO << ' ';
            }
            break;
        }
    }
    xOptimal = xO.str();
    yOptimal = yO.str();
    reverse(xOptimal.begin(), xOptimal.end());
    reverse(yOptimal.begin(), yOptimal.end());
    fout << xOptimal << nl << yOptimal << nl;
    cout << dp[n][m] << nl;
}