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
#define MAX (int)1e7 + 10

vector<int> dp[3]; // 0 for D, 1 for A, 2 for B, 3 for C

struct Matrix {
    int a[4][4] = {};
    Matrix operator*(Matrix that) {
        Matrix result;
        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 4; j++)
                for (int k = 0; k < 4; k++)
                    result.a[i][k] += (((a[i][j] % 1000000007) * (that.a[j][k] % 1000000007)) % 1000000007) % 1000000007;
        return result;
    }
};


signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    Matrix m;
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            if (i == j)
                m.a[i][j] = 0;
            else    
                m.a[i][j] = 1;

    int n; cin >> n;

    Matrix a;
    for (int i = 0; i < 4; i++)
        a.a[i][i] = 1;
    
    while (n > 0) {
        if (n & 1)
            a = a * m;

        m = m * m;
        n >>= 1;
    }

    // for (int i = 0; i < 4; i++) {
    //     for (int j = 0; j < 4; j++)
    //         cout << a.a[i][j] << ' ';
    //     cout << nl;
    // }

    cout << (a.a[0][0] + 1000000007) % 1000000007  << nl;
}

// int32_t main() {
//     ios_base::sync_with_stdio(false); cin.tie(0);

//     dp[0].resize(4);
//     dp[1].resize(4);
//     dp[2].resize(4);

//     dp[0][0] = 1;
//     dp[1][1] = dp[1][2] = dp[1][3] = 1;

//     int n; cin >> n;

//     for (int i = 2; i <= n; i++) {
//         dp[2][1] = 1 * dp[1][2] + 1 * dp[1][3] + 1 * dp[1][4];  
//         dp[2][1] = 1 * dp[1][0] + 1 * dp[1][2] + 1 * dp[1][3];  
//         dp[2][2] = 1 * dp[1][0] + 1 * dp[1][1] + 1 * dp[1][3];  
//         dp[2][3] = 1 * dp[1][0] + 1 * dp[1][1] + 1 * dp[1][2];  

//         dp[1] = dp[2];
//     }

//     cout << (dp[1][0]) % 1000000007  << nl;
// }   