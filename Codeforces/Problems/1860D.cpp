#include <bits/stdc++.h>
#define int long long
#define nl " \n"
#define pi pair<int, int>
#define ff first
#define ss second

using namespace std;
const int mxn = 100;
int a[mxn];
int dp[2][mxn+1][mxn * mxn + 1];

signed main() {
    cin.tie(0)->sync_with_stdio(false); 
    
    int n; string sss; cin >> sss;
    n = sss.size();
    for (int i = 0; i < n; i++)
        a[i] = sss[i] & 1;
    
    int b = 0;
    int s0 = 0;
    for (int i = 0; i < n; i++)
        s0 += !a[i],
        b += (a[i] * s0);
    int s1 = 0;
    int c = 0;
    for (int i = n - 1; i >= 0; i--)
        s1 += !a[i],
        c += (a[i] * s1);
    
    for (int j = 0; j <= n; j++)
        for (int k = 0; k <= n * n; k++)
            dp[0][j][k] = INT_MAX;

    dp[0][1][0] = a[0];
    dp[0][0][0] = !a[0];

    for (int i = 1; i < n; i++) {
        for (int j = 0; j <= i + 1; j++)
            for (int k = 0; k <= j * (i - j + 1); k++)
                dp[1][j][k] = INT_MAX;

        for (int j = 0; j <= i; j++)
            for (int k = 0; k <= j * (i - j); k++) {
                dp[1][j + 1][k] = min(dp[1][j + 1][k], dp[0][j][k] + a[i]);
                dp[1][j][k + j] = min(dp[1][j][k + j], dp[0][j][k] + !a[i]);
            
                //cout << i << " " << j << " " << k << " : " << dp[1][j + 1][k] << nl;
            }
        swap(dp[0], dp[1]); 
    }
    
    cout << dp[0][s1][(b + c) / 2]  / 2<< nl;
}
