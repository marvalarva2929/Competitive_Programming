using namespace std;
#include <bits/stdc++.h>
#define nl '\n'
#define f first
#define s second
#define int long long
#define yes "yes"
#define no "no"
#define MAX (int)1e5 + 10
int a[MAX];

void solve() {
    int n, m, k; cin >> n >> m >> k;
    for (int i = 0; i < m; i++)
        cin >> a[i];

    if (k > m) {
        cout << no << nl;
        return;
    }

    int maxA = ceil((double)n/k);
    int cnto = 0;

    for (int i = 0; i < m; i++)
        if (a[i] > maxA) {
            cout << no << nl;
            return;
        } else if (a[i] == maxA)
            cnto++;

    if (cnto > ((n - 1) % k) + 1) {
        cout << no << nl;
        return;
    }

    cout << yes << nl;
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    int t; cin >> t;
    while (t--)
        solve();
}