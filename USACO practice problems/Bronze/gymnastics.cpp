using namespace std;
#include <bits/stdc++.h>
#define int long long
#define nl '\n'
int placeOf[10][20];

signed main() {
    ifstream cin("gymnastics.in");
    ofstream cout("gymnastics.out");

    int k, n; cin >> k >> n;
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < n; j++) {
            int cow; cin >> cow;
            placeOf[i][--cow] = j;
        }
    }

    int ans = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j) {
                bool works = 1;
                for (int m = 0; m < k; m++)
                    works &= (placeOf[m][i] < placeOf[m][j]);
                ans += works;

                // cout << i << " " << j << " , " << works << nl;
            }
        }
    }
    
    cout << ans << nl;
}