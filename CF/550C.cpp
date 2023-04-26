#include <iostream>
#include <algorithm>
#include <sstream>
#include <cmath>
#include <vector>
#define nl '\n'
#define MAX (int)200
#define ll long long
using namespace std;
bool dp[MAX][8];
int p[MAX][MAX];

int main() {
    stringstream ss;
    string c;
    getline(cin, c);
    vector<int> digits;
    ss << c;
    char a;
    while (ss >> a) {
        digits.push_back(a - '0');
        // cout << "found " << a << nl;
    }
    for (int i = 1; i <= digits.size(); i++) {
        int digit = digits[i - 1];
        // cout << "checking digit " << digit << ": " << i << nl;
        dp[i][digit % 8] = true;
        p[i][digit % 8] = -1;
        for (int j = 0; j < 8; j++) {
            if (dp[i - 1][j] == true) {
                dp[i][j] = true;
                p[i][j] = j;
                dp[i][((j * 10) + digit) % 8] = true;
                p[i][((j * 10) + digit) % 8] = j; 
            }
            // if (digit == 2) cout << dp[i - 1][7] << " 00 " << nl;
        }
    }
    // for (int i = 1; i <= digits.size(); i++) {
    //     for (int j = 0; j < 8; j++) {
    //         // cout << "digits up to " << i << " with a mod of "  << j << " exist: " << dp[i][j] << ": previous digit was " << p[i][j] << nl;
    //     }
    // }

    if (dp[digits.size()][0] == true) {
        int j = 0;
        int i = digits.size();
        int ans = 0;
        cout << "YES" << nl;
        int iter = 0;
        while (i) {
            // cout << ans << nl;
            if (p[i][j] != j) {
                ans += (digits[i - 1] * (int)ceil(pow(10, iter++)));
            }
            // cout << i << ": " << j << " -- " << digits[i - 1] << ": " << p[i][j] << nl;
            // cout << ans << nl;
            if (p[i][j] == -1) break;
            j = p[i][j];
            i--;
        }
        cout << ans << nl;
    } else {
        cout << "NO" << nl;
    }
}