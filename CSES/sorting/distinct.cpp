#include <bits/stdc++.h>
#define int long long
#define nl " \n"

using namespace std;

signed main() {
    int n; cin >> n;
    set<int> a;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        a.insert(x);
    }
    cout << a.size() << nl;
}
