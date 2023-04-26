using namespace std;
#include <bits/stdc++.h>
#define int long long
#define nl '\n'
#define f first
#define s second
#define pi pair<long, long>
#define MAX (int)5e5 + 10
int a[MAX];
int b[MAX];
int n, m;

void solve() {
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> a[i], b[i] = a[i];

    sort(a, a + n);
    int wins = 0;

    for (int i = 0; i < n; i++)
        if (a[i] <= m) m -= a[i], wins++;
        else break;

    if (wins && wins < n && a[wins - 1] + m >= b[wins]) wins++;

    cout << n - wins + 1 << nl;
    
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t; cin >> t;
    while (t--)
        solve();
}