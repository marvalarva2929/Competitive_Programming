#include <bits/stdc++.h>
#define int long long
#define nl " \n"
#define pi pair<int, int>
#define ff first
#define ss second

using namespace std;

const int mxn = 2e5;
int a[mxn], loc[mxn +1];

void solve() {
    int n; cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i], loc[a[i]] = i + 1;
    
    if (loc[2] < loc[1] != loc[n] < loc[1]) {
        cout << loc[1] << " " << loc[n] << nl;
    } else if (loc[1] < loc[2] && loc[2] < loc[n])
        cout << loc[2] << " " << loc[n] << nl;
    else if (loc[n] < loc[2] && loc[2] < loc[1])
        cout << loc[2] << " " << loc[n] << nl;
    else cout << 1 << " " << 1 << nl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t; 
    cin >> t;
    while (t--)
        solve();
}
