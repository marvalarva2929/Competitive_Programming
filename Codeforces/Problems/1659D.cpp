#include <bits/stdc++.h>
#define int long long
#define nl " \n"

using namespace std;

const int mxn = 2e5;
int a[mxn];
bool ans[mxn];

void solve(int t) {
    int n; cin >> n;
    
    fill(ans, ans + n, 1);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    for (int i = 0; i < n; i++) {
        if (!a[i]) {
            ans[i] = 0;
            continue;
        }

        if (ans[i])
            ans[a[i]] = 0;
        else if (a[i] + i < n) ans[a[i] + i] = 0;
    } 
    
    for (int i = 0; i < n; i++)
        cout << ans[i] << nl[i == n- 1];

}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t; cin >> t;
    for (int i = 1; i <= t; i++)     
        solve(i);
}
