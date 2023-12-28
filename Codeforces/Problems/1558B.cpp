#include <bits/stdc++.h>
#define int long long
#define nl " \n"
#define pi pair<int, int>
#define ff first
#define ss second

using namespace std;
const int mxn = 8e6;
int a[mxn+1], suff[mxn + 1];

signed main() {
    cin.tie(0)->sync_with_stdio(false);
    
    int n, m; cin >> n >> m;
    a[n] = 1, suff[n] = 1;
    int s = 1;

    for (int i = n - 1; i >= 1; i--) {
        a[i] = a[i] +  suff[i + 1] % m;
        for (int j = 2; j * i <= n; j++) {
            a[i] = a[i] + suff[i * j] % m - suff[min((i + 1) * j, n + 1)] % m; 
        }
        suff[i] = a[i] + suff[i + 1] % m;
    }

    cout << a[1] % m << nl;
}
