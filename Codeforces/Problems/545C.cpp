#include <iostream>
#include <vector>
#define nl '\n'
#define MAX (int)1e5 +10
using namespace std;
int dp[MAX][3]; // 0 for left, 1 for standing, 2 for right
int h[MAX];
int x[MAX];

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> x[i] >> h[i];

    dp[1][0] = 1;
    dp[1][1] = 0;
    dp[1][2] = 1;

    for (int i = 2; i <= n; i++) {
        int pTree = i - 1;
        if (x[pTree] + h[pTree] < x[i] - h[i]) { // the previous tree fell right and there is still room to fall left
            dp[i][0] = dp[pTree][2] + 1;
            dp[i][1] = max(dp[pTree][0], max(dp[pTree][1], dp[pTree][2]));
            dp[i][2] = max(dp[pTree][0], max(dp[pTree][1], dp[pTree][2])) + 1;
        } else if (x[pTree] + h[pTree] < x[i]) { // the previous tree fell right but there is no room to fall left
            dp[i][0] = 0;
            dp[i][1] = max(dp[pTree][0], max(dp[pTree][1], dp[pTree][2]));
            dp[i][2] = max(dp[pTree][0], max(dp[pTree][1], dp[pTree][2])) + 1;
            if (x[pTree] < x[i] - h[i]) { // the previous tree either stayed or fell left
                dp[i][0] = max(dp[i][0], max(dp[pTree][1], dp[pTree][0]) + 1); 
                dp[i][1] = max(dp[i][1], max(dp[pTree][1], dp[pTree][0]));
                dp[i][2] = max(dp[i][2], max(dp[pTree][1], dp[pTree][0]) + 1);
            } else { // there is no room for the current tree to fall left nor for the previous tree to fall right
                dp[i][0] = max(dp[i][0], dp[pTree][0]); 
                dp[i][1] = max(dp[i][1], max(dp[pTree][0], dp[pTree][1]));
                dp[i][2] = max(dp[i][2], max(dp[pTree][0], dp[pTree][1]) + 1);
            }
        } else if (x[pTree] < x[i] - h[i]) { // the previous tree either stayed or fell left
            dp[i][0] = max(dp[pTree][1], dp[pTree][0]) + 1; 
            dp[i][1] = max(dp[pTree][1], dp[pTree][0]);
            dp[i][2] = max(dp[pTree][1], dp[pTree][0]) + 1;
        } else { // there is no room for the current tree to fall left nor for the previous tree to fall right
            dp[i][0] = dp[pTree][0]; 
            dp[i][1] = max(dp[pTree][0], dp[pTree][1]);
            dp[i][2] = max(dp[pTree][0], dp[pTree][1]) + 1;
        }
    }
    cout << max(dp[n][0], max(dp[n][1], dp[n][2])) << nl;
}