#include <bits/stdc++.h>
#define int long long
#define pi pair<int, int>
#define ff first
#define ss second
#define nl " \n"

using namespace std;
int a[100];

void solve() {
    int n; cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    if (n % 2 == 0) {
        cout << 2 << nl << 1 << " " << n << nl << 1 << " " << n << nl;    
    }  else {
        cout << 4 << nl << 1 << " " << n - 1 << nl << 1 << " " << n - 1 << nl;    
        cout << n - 1 << " " << n << nl << n - 1 << " " << n << nl;    
    } 
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t; cin >> t;
    while (t--)
        solve();
}
