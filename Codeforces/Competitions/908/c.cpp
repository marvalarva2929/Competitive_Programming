#include <bits/stdc++.h>
#define int long long
#define nl " \n"
#define pi pair<int, int>
#define ff first
#define ss second

using namespace std;
const int mxn = 2e5;
int a[mxn], to[mxn];

bool solve() {
    int n, k; cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    
    vector<bool> vis(n, 0);
    for (int i = 0; i < n; i++) {
        int t = i - a[i]; 
        t += (abs(t) + n - 1)/n * n;
        t %= n;

        if (a[i] <= n) to[i] = t;
        else to[i] = -1; 
    }
    
    int cur = n -1;
    int r = 0; 
    while (r < k && !vis[cur]) {
        vis[cur] = 1; 
        cur = to[cur];
        r++;
        if (cur == -1) return 0; 
    }
    
    return 1; 
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t; cin >> t;
    while (t--)
        cout << (solve() ? "YES" : "NO") << nl;
}
