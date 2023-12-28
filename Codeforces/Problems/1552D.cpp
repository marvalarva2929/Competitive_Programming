#include <bits/stdc++.h>
#define int long long
#define pi pair<int, int>
#define ff first
#define ss second
#define nl " \n"

using namespace std;
const int mxa = 1e6 + 1;
int a[10];

bool solve() {
    int n; cin >> n;
    bitset<mxa> c;
    c[0] = 1;

    for (int i = 0; i < n; i++)
        cin >> a[i], a[i] = abs(a[i]);
    sort(a, a + n);
    
    bitset<mxa> b; b[0] = 1;
    for (int i = 0; i < n; i++) {
        bitset<mxa> nb = (b << a[i]);
        if ((nb & b).count() != 0) return true;
        b |= nb;
    }
    
    return false;
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t; cin >> t;
    while (t--)
        cout << (solve() ? "YES" : "NO") << nl;
}
