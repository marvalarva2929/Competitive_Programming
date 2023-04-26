using namespace std;
#include <bits/stdc++.h>
#define int long long
#define nl '\n'

signed main() {
    ifstream cin("diamond.in");
    ofstream cout("diamond.out");

    int n, k; cin >> n >> k;

    int a[n] = {};
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort (a, a + n);

    // for (int i : a)
    //     cout << i << " ";
    // cout << nl;

    int j = 0, i = 0;
    int ans = 0;

    while (i < n) {
        while (a[j] - a[i] <= k && j < n) j++;
        ans = max(ans, j - i);
        i++;
    }

    cout << ans << nl;
}