using namespace std;
#include <bits/stdc++.h>
#define int long long
#define nl '\n'
#define MAX (int)262144
int a[MAX] = {};

void swp(int i, int t) {
    for (int j = i; j < i + t/2; j++) 
        swap(a[j], a[j + t/2]);

}

void solve() {
    int n; cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int t = 2;
    int iter = 1;
    int ans = 0;

    while (t <= n) {
        for (int i = 0; i < n; i += t) {    
            if (a[i] + t/2 != a[i + t/2] && a[i] != a[i + t/2] + t/2) {
                cout << -1 << nl;
                return;
            } else if (a[i] == a[i + t/2] + t/2) 
                swp(i, t), ans++;
        }
        t *= 2;
    }

    cout << ans << nl;
    return;
}
signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t; cin >> t;
    while (t--)
        solve();
}