#include <bits/stdc++.h>
#define int long long
#define nl " \n"
#define pi pair<int, int>
#define ff first
#define ss second

using namespace std;
const int mxn = 1e5;
int adj[mxn];

int p2(int x) {
    int ans = 0, cur = 1;
    while (cur <= x) cur <<= 1, ans++;
    return ans;
}


signed main() {
    cin.tie(0)->sync_with_stdio(false);
    
    int ans = 0;
    int n; cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int a, b; cin >> a >> b; --a, --b;
        adj[a]++;
        adj[b]++;
    }
    adj[0]++;

    for (int i = 0; i < n; i++)
        ans += p2(adj[i] - 1);
   
    cout << ans + n - 1 << endl;
}
