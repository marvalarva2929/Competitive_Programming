#include <bits/stdc++.h>
#define int long long
#define nl " \n"
#define pi pair<int, int>
#define ff first
#define ss second

using namespace std;

template<class T> using V = vector<T>;
const int mxn = 5e4;
int a[mxn];

void solve() {
    int n; cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int x; cin >> x;
    for (int i = 0; i < n; i++)
        a[i] -= x;

    V<int> m(n, 1);    
    
    for (int i = 0; i < n; i++) {
        int s = a[i]; 
        for (int j = i - 1; j > max((int)-1, i - 3); j--) {
            if (!m[j]) break;
            s += a[j];
            if (s < 0) {
                m[i] = 0;
                break;
            }
        } 
    }
    
    x = 0;
    for (int i = 0; i < n; i++)
        x += m[i];

    cout << x << nl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t; cin >> t;
    while (t--)
        solve();
}
