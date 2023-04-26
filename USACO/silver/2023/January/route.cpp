using namespace std;
#include <bits/stdc++.h>
#define int long long
#define nl '\n'
#define print(x) for (auto i : x) { cout << i << " "; } cout << nl;
signed main() {
    int n; cin >> n;
    int a[n + 1] = {};
    for (int i = 0; i < n; i++)
        cin >> a[i];

    string ans;
    int x = 0;

    while (!(x == 0 && a[x] == 0)) {
        while (a[x] > 0) {
            ans += 'R';
            a[x]--;
            x++;
        }
        while (x > 0 && (a[x] == 0 || a[x - 1] > 1)) {
            ans += 'L';
            x--;
            a[x]--;
        }
    }
    
    cout << ans << nl;
}