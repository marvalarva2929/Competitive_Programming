#include <bits/stdc++.h>
#define int long long
#define pi pair<int, int>
#define ff first
#define ss second
#define nl " \n"

using namespace std;
const int mxn = 1e5;
pi a[mxn];

signed main() {
    cin.tie(0)->sync_with_stdio(false);
    
    ifstream cin("sort.in");
    ofstream cout("sort.out");

    int ans = 0;
    int n; cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i].ff, a[i].ss = i;
    sort(a, a + n);
    
    for (int i = 0; i < n; i++)
        ans = max(ans, a[i].ss - i);

    cout << ans + 1 << endl;
}
