#include <bits/stdc++.h>
#define int long long
#define nl " \n"
#define pi pair<int, int>
#define ff first
#define ss second

using namespace std;

const int mxn = 2e5;
bool a[mxn];

void solve() {
    int n, q; cin >> n >> q; 
    
    for (int i = 0; i < n; i++) {
        char c; cin >> c;
        a[i] = c == '(';
    }
    
    set<int> check;
    for (int i = 0; i < n; i++)
        if (i % 2 == a[i])
            check.insert(i);

    if (n % 2) {
        for (int i = 0; i < q; i++) {
            int x; cin >> x;
            cout << "NO" << nl;
        }
        return;
    }
    
    for (int i = 0; i < q; i++) {
        int x; cin >> x; --x;
        if (!check.count(x)) check.insert(x);
        else check.erase(x);
        a[x] = !a[x]; 
        //cout << check.size() << " " << *check.begin() << " " << *check.rbegin() << nl;

        if (check.empty() || (a[*check.begin()] && !a[*check.rbegin()])) {
            cout << "YES" << nl;
        } else cout << "NO" << nl; 
    }
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t = 1;
    while (t--)
        solve();
}
