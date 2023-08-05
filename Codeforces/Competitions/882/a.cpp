#include <bits/stdc++.h>
#define int long long
#define nl " \n"
#define pi pair<int, int>
#define ff first
#define ss second

using namespace std;
const int mxn = 100;
int a[mxn];

void solve() {
    int n, k; cin >> n >> k;
    k--;
    
    for (int i = 0; i < n; i++)
        cin >> a[i];
    
    vector<int> all;

    int s = 0;
    for (int i = 1; i < n; i++)
        s += abs(a[i] - a[i - 1]), all.push_back(abs(a[i] - a[i - 1]));

    sort(all.begin(), all.end(), greater<int>());

    for (int i = 0; i < k; i++)
        s -= all[i];

    cout << s << nl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t; cin >> t;
    while (t--)
        solve();
}
