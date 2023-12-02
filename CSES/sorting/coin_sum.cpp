#include <bits/stdc++.h>
#define int long long
#define pi pair<int, int>
#define ff first
#define ss second
#define nl " \n"

using namespace std;
const int mxn = 2e5;
int a[mxn];

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int n; cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n);

    int cur = 1;
    int s = 0;

    for (int i = 0; i < n; i++)
        if (a[i] > cur) { cout << cur << nl; return 0; }
        else cur += a[i];
    
    cout << cur << nl;
}
