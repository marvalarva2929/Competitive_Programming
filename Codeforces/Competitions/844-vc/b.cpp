#include <bits/stdc++.h>
#define int long long
#define nl " \n"
#define pi pair<int, int>
#define ff first
#define ss second

using namespace std;

void solve() {
    int n; cin >> n;
    
    if (n == 1) cout << 1 << nl;
    else if (n == 2) cout << 1 << " " << 2 << nl;
    else {

        vector<int> a(n);
        a[n - 1]  = 2;
        a[n/2] = 1;
        a[0] = 3;

        vector<int> x;
        for (int i = 4; i <= n; i++)
            x.push_back(i);
        

        int cnt = 0;

        for (int i = 0; i < n; i++)
            cout << (a[i] ? a[i] : (x[cnt++])) << nl[i == n -1 ];  
    }
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t; cin >> t;
    while (t--)
        solve();
}
