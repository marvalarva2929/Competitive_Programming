#include <bits/stdc++.h>
#define int long long
#define nl " \n"
#define pi pair<int, int>
#define ff first
#define ss second

using namespace std;

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        if (!(x & 1)) {
            cout << "lunchbox" << nl;
            return 0;
        }
    }

    cout << "hihitherethere" << nl;
}
