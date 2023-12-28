#include <bits/stdc++.h>
#define int long long
#define pi pair<int, int>
#define ff first
#define ss second
#define nl " \n"

using namespace std;
const int mxn = 100;
int a[mxn];

bool solve() {
    int n, k; cin >> n >> k; 
    for (int i = 0; i < n; i++)
        cin >> a[i];
    
    if (k > 1) return true;
    
    bool ok = 1;
    for (int i = 1; i < n; i++)
        ok &= a[i] >= a[i - 1]; 
    return ok;
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t; cin >> t;
    while (t--)
        cout << (solve() ? "YES" : "NO") << nl;
}
