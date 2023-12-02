#include <bits/stdc++.h>
#define int long long
#define nl " \n"
#define pi pair<int, int>
#define ff first
#define ss second

using namespace std;
const int mxn = 2e5;
int a[mxn], b[mxn];
int n, m;

void solve() {
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < m; i++)
        cin >> b[i];
    
    sort(b, b + m, greater<int>());

    int i = 0, j = 0;
    vector<int> c;

    while (j < m || i < n) {
        while (i < n && (j == m || a[i] >= b[j])) c.push_back(a[i++]);
        while (j < m && (i == n || b[j] > a[i])) c.push_back(b[j++]);
    }
    
    for (int x : c)
        cout << x << " ";
    cout << nl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t; cin >> t;
    while (t--)
        solve();
}
