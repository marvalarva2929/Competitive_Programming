#include <bits/stdc++.h>
#define int long long
#define pi pair<int, int>
#define ff first
#define ss second
#define nl " \n"

using namespace std;
const int mxn = 2e5;
int a[mxn];

int solve() {
    int n; cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int ans = 0;
    for (int i = 0; i < n; i++)
        ans += ((i + 1) * a[i]);
    
    int s = 0;
    for (int i = n - 1; i; i--) { 
        s += a[i];
        if (s < 0) ans -= s;
    }
    
    return ans;
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t; cin >> t;
    while (t--)
        cout << solve() << nl;
}
