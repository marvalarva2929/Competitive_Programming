using namespace std;
#include <bits/stdc++.h>
#define int long long
#define nl '\n'

void solve() {
    int a, b; cin >> a >> b;

    int t_a = a, t_b = b;

    int ans_1 = 1, ans_2 = 1;

    while ((a | b) != b && a != b) { 
        ans_1++;
        b++;
        if ((a | b) == b && a == b) ans_1--;
    }

    a = t_a, b = t_b;

    while ((a | b) != b && a != b) {
        ans_2++; 
        a++;
        if ((a | b) == b && a == b) ans_2--;
    }

    cout << min(ans_1, ans_2) << nl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t; cin >> t;
    while (t--)
        solve();
}