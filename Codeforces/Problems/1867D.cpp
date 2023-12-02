#include <bits/stdc++.h>
#define int long long
#define nl " \n"
#define ff first
#define ss second

using namespace std;
const int mxn = 2e5;
int a[mxn], vis[mxn], ord[mxn];

bool solve() {
    int n, k; cin >> n >> k;
    
    for (int i = 0; i < n; i++)
        cin >> a[i], a[i]--;
    fill(vis, vis + n, 0);
        
    if (k == 1) {
        for (int i = 0; i < n; i++)
            if (a[i] != i) return 0;
        return 1;
    }

    for (int i = 0; i < n; i++)
        if (!vis[i]) {
            int cur = i;
            int cnt = 0;
            while (!vis[cur]) {
                ord[cur] = cnt++;
                vis[cur] = i + 1;
                cur = a[cur];
            }
            if (vis[cur] != i + 1) continue;
            if (cnt - ord[cur] != k) return 0;
        }
    
    return 1;

}

signed main() {
    cin.tie(0)->sync_with_stdio(false);
    
    int t; cin >> t;
    while (t--)
        cout << (solve() ? "YES" : "NO") << nl;
}
