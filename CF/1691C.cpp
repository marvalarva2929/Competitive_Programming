using namespace std;
#include <bits/stdc++.h>
#define int long long
#define nl '\n'
#define MAX (int)1e5 + 10;

void solve() {
    int n, k; cin >> n >> k;
    string s; cin >> s;
    int a[n] = {};
    for (int i = 0; i < n; i++)   
        a[i] = (s[i]&1);

    int ans = 0;

   

    for (int i = n - 2; !a[n - 1] && i >= max((int)0, n - k - 1); i--)
        if (a[i]) {
            swap(a[i], a[n - 1]);
            k -= (n - 1 - i);
            break;
        }

    for (int i = 1; !a[0] && i < min(n - 1, k + 1); i++)
        if (a[i]) {
            swap(a[0], a[i]);
            break;
        }

    // for (int i : a)
    //     cout << i << " ";
    // cout << nl;

    for (int i = 0; i < n - 1; i++)
        ans += (a[i] ? 10 : 0) + (a[i + 1] ? 1 : 0);

    cout << ans << nl;


    

}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t; cin >> t;
    while (t--)
        solve();
}