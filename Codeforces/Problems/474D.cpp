#include <iostream>
#define nl '\n'
#define MAX (int)1e5 + 10
#define int long long
using namespace std;
int dp[MAX];
int sums[MAX];

int32_t main() {
    cin.tie(nullptr);
    int t, k;
    cin >> t >> k;
    dp[0] = 1;
    for (int i = 1; i <= MAX; i++) {
        dp[i] = dp[i - 1] + (i >= k ? dp[i - k] : 0) % 1000000007;
    }
    for (int i = 1; i <= MAX; i++) 
        dp[i] = dp[i - 1] + dp[i] % 1000000007;

    for (int i = 0; i < t; i++) {
        int x, y;
        cin >> x >> y;
        cout << (dp[y] - dp[x - 1]) % 1000000007 << nl;
    }

}