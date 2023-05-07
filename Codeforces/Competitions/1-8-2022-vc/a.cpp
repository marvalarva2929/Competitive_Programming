using namespace std;
#include <bits/stdc++.h>
#define int long long
#define nl '\n'

void solve() {
    int n; cin >> n;
    int a[n] = {};
    for (int i = 0; i < n; i++)
        cin >> a[i];

    set<int> check;
    for (int i : a)
        check.insert(i);
    if (check.size() == 1) {
        cout << "NO" << nl;
        return;
    }

    if (n == 2) {
        cout << "YES" << nl;
        cout << a[1] << " " << a[0] << nl;
        return;
    }

    sort(a, a + n, greater<int>());
    cout << "YES" << nl;
    cout << a[0] << " ";
    int i = 1; 
    while (a[i] == a[0] && i < n) i++;
    cout << a[i] << " ";
    for (int j = 1; j < i; j++)
        cout << a[j] << " ";
    for (int j = i + 1; j < n; j++)
        cout << a[j] << " ";
    cout << nl;
}   

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t; cin >> t;
    while (t--)
        solve();
}