#include <bits/stdc++.h>
#define nl " \n"
#define int long long
#define ff first
#define ss second
#define pi pair<int, int>

using namespace std;
const int mxn = 2000;
int dp[mxn + 1][mxn * 2 + 1];
int n, aa, bb;

signed main() {
    cin.tie(0)->sync_with_stdio(false);
        
    cin >> n >> aa >> bb;
    vector<vector<int>> a = vector<vector<int>>(n, vector<int>(3, 0));

    for (int i = 0; i < n; i++) {
        cin >> a[i][1] >> a[i][2] >> a[i][0]; // p c x 
    }

    sort(a.begin(), a.end(), 
            [](vector<int>& x, vector<int>& b) -> bool {
                return x.front() < b.front();
                });
    
    memset(dp, -1, sizeof dp);
    dp[0][aa + bb] = 0;
    
    for (int i = 0; i < n; i++) {
        int x = a[i][0], p = a[i][1], c = a[i][2];
       
        for (int j = aa + bb; j >= 0; j--) {
            if (dp[i][j] == -1) continue;
           
            int cones = max((int)0, j - aa);
            
            //cout << i << " : " << x << " " << p << " " << c << nl; 
            //cout << i << " : " << j << " " << dp[i][j] << nl;

            dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);

            if (cones >= c * x) dp[i + 1][j - c * x] = max(dp[i + 1][j - c * x], dp[i][j] + p);
            else if (cones) {
                int left = c - (cones / x);
                dp[i + 1][aa - left] = max(dp[i + 1][aa - left], dp[i][j] + p); 
            } else if (j >= c && j <= aa)
                dp[i + 1][j - c] = max(dp[i + 1][j - c], dp[i][j] + p);
        }
    } 
  // 
  //  for (int i = 0; i <= aa + bb; i++)
  //      cout << i << " : " << dp[n][i] << nl;

    cout << *max_element(dp[n], dp[n] + bb + aa + 1) << endl;
}

