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
#define f first
#define s second
#define MAX (int)201
int grid[MAX][MAX];
int n;

int32_t main() {
    cin >> n;
    int total = 0;
    for (int i = 1; i <= n; i++) 
        for (int j = 1; j <= n; j++){
            cin >> grid[i][j];
            total += grid[i][j];
        }
    
    int ans = INT_MIN;
    for (int i = 1; i <= n; i++) {
        ans = max(ans, total - grid[i][n - i + 1]);
    }
    cout << ans << nl;
} 