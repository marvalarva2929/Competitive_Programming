#include <bits/stdc++.h>
#define int long long
#define nl " \n"
#define pi pair<int, int>
#define ff first
#define ss second

using namespace std;
const int mxn = 2e5;
int a[mxn], b[mxn];

void solve() {
    int n, k; cin >> n;
    int mn = LLONG_MAX;
    for (int i = 0; i < n; i++)
        cin >> a[i], mn = min(mn, a[i]);
    cin >> k;
    fill(b, b + n, 0);
    int x = k / mn;
    mn = LLONG_MAX; 
    
    vector<pi> is;
    
    for (int i = n - 1; i >= 0; i--) {
        if (a[i] < mn) is.emplace_back(a[i], i), mn = a[i];
        if (k / a[i] == x) break;
    }
    reverse(is.begin(), is.end());
    
    b[is[0].ss] += x; 
    k %= is[0].ff;

    int i = 0;
    while (i < is.size() - 1) {
        if (k == 0) break;

        int j = i + 2;
        
        while (j < is.size() && (k / (is[j].ff - is[i].ff)) == (k / (is[i + 1].ff - is[i].ff))) j++;
        j--; 
        int ex = is[j].ff - is[i].ff;
        b[is[j].ss] += k / ex;
        b[is[i].ss] -= b[is[j].ss];
        k %= ex;

        i = j;
    }

    for (int i = n - 2; i >= 0; i--)
        b[i] += b[i + 1];

    for (int i = 0; i < n; i++)
        cout << b[i] << nl[i == n - 1];
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t; cin >> t;
    while (t--)
        solve();
}
