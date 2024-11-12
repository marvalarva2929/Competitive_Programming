#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int cnt = 1;
    int ans = 0;
    char lst = '-';

    string c; cin >> c;
    c += '+';

    for (int i = 0; i < c.size(); i++) {
        if (c[i] == lst) cnt++;
        else ans = max(ans, cnt), cnt = 1;
        lst = c[i];
    }
    
    cout << ans << endl;
}
