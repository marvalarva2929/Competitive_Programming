using namespace std;
#include <bits/stdc++.h>
#define int long long
#define nl '\n'
#define MAX (int)2e5 + 10
int a[MAX];
int n;

bool check(int x) {
    vector<int> c_a;
    for (int i = 1; i <= x; i++)
        c_a.push_back(i);
    for (int i = 0; i < n; i++)
        if (a[i] > x && a[i] < (n - x + 1))
            c_a.push_back(a[i]);
    for (int i = (n - x + 1); i <= n; i++)
        c_a.push_back(i);

    // cout << x << "  : "  << nl;
    // for (int i : c_a)
    //     cout << i << " ";
    // cout << nl;


    for (int i = 1; i < n; i++)
        if (c_a[i] < c_a[i - 1]) 
            return false;

    return true;
}

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int l = 0, r = n/2;
    while (l < r) {
        int m = (l + r) >> 1;
        if (check(m))
            r = m;
        else l = m + 1;
    }

    cout << l << nl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t; cin >> t;
    while (t--)
        solve();
}