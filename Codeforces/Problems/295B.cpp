using namespace std;
#include <bits/stdc++.h>
#include <string.h>
typedef long long ll;
typedef vector<int> vi;
typedef vector<pair<int,int>> vpi;
#define pb push_back
#define int long long
#define nl '\n'
#define rsz resize
#define sz(x) int(x.size())
#define all(x) begin(x), end(x)
#define no "no"
#define yes "yes"
#define print(x, y, z) for (int i = y; i <= z; i++) {cout << x[i] << " ";} cout << nl;
#define MAX (int)500 + 10
int order[MAX];
int dp[MAX][MAX];
int ans[MAX];

int32_t main() {
    int n;
    cin >> n;


    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) 
            cin >> dp[i][j];
        
    
    for (int i = 0; i < n; i++) 
        cin >> order[i + 1];
    
    
    reverse(order + 1, order + n + 1);

    for (int ii = 1; ii <= n; ii++) { 
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) {
                dp[i][j] = min(dp[i][j], dp[i][order[ii] - 1] +  dp[order[ii] - 1][j]);
                // cout << ii << " : " << i << " : " << j << " : " << dp[i][j] << nl;
            }
        
        for (int i = 1; i <= ii; i++)
            for (int j = 1; j <= ii; j++)
                ans[ii] += dp[order[i] - 1][order[j] - 1];
    }
        
    
    reverse(ans + 1, ans + n + 1);

    for (int i = 1; i <= n; i++)
        cout << ans[i] << ' ';
    cout << nl;
} 