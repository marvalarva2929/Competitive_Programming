using namespace std;
#include <bits/stdc++.h>
#define int long long
#define nl '\n'

const int mxn = (int)1000 + 10;
int p[mxn][mxn];

signed main() {
    ifstream cin("paintbarn.in");
    ofstream cout("paintbarn.out");
    int n, k; cin >> n >> k;
    for (int i = 0; i < n; i++) {
        int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
        x1++, y1++, x2++, y2++;
        p[x1][y1]++;
        p[x2][y2]++;
        p[x1][y2]--;
        p[x2][y1]--;
    }

    for (int i = 1; i < mxn; i++) 
        for (int j = 1; j < mxn; j++)
            p[i][j] += p[i - 1][j] + p[i][j - 1] - p[i - 1][j - 1];
    
    int ans = 0;
    for (int i = 1; i < mxn; i++)
        for (int j = 1; j < mxn; j++)
            if (p[i][j] == k)
                ans++;
    cout << ans << nl;
}