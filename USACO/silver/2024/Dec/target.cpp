#include <bits/stdc++.h>
#define int long long
#define nl " \n"
#define pi pair<int, int>
#define ff first
#define ss second

using namespace std;
const int mxn = 1e5;
int a[mxn], t[mxn];
int dp[mxn][1];
int m, n;

signed main() {
    cin.tie(0)->sync_with_stdio(false);
    set<int> allt;

    cin >> m >> n;
    for (int i = 0; i < m; i++)
        cin >> t[i], allt.insert(t[i]);

    for (int i = 0; i < n; i++) {
        char c; cin >> c;
        a[i] = (c == 'L' ? -1 : c == 'R' ? 1 : 0);
    }

} 
