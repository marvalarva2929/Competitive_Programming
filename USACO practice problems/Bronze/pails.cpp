using namespace std;
#include <bits/stdc++.h>
#define int long long
#define nl '\n'


signed main() {
    ifstream cin("pails.in");
    ofstream cout("pails.out");
    
    int x, y, m; cin >> x >> y >> m;
    int ans = 0;

    for (int i = 0; i <= 1000; i++)
        for (int j = 0; j <= 1000; j++)
            if ((i * x) + (j * y) <= m)
                ans = max(ans, (i * x) + (j * y));
    
    cout << ans << nl;
}