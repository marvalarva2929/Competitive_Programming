using namespace std;
#include <bits/stdc++.h>
#define int long long
#define nl '\n'
#define inf LLONG_MAX
#define MAX (int)1e5 + 10
vector<int> factors[MAX];

void solve() {
    int n, m; cin >> n >> m;
    int a[n] = {};
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n);

    int cnt = 0;
    unordered_map<int, int> f;
    int ans = inf;

    int j = 0;
    for (int i = 0; i < n; i++) {
        // cout << i << " " << j << " : " << cnt << nl;
        for (int factor : factors[a[i]])
            if (factor > m) break;
            else if (!f[factor]++)
                cnt++;

        while (cnt == m) {
            ans = min(ans, a[i] - a[j]);
            for (int factor : factors[a[j]])
                if (factor > m) break;
                else if (--f[factor] == 0)
                    cnt--;
            j++;
        }
    }
    cout << (ans == inf ? -1 : ans) << nl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    for (int i = 1; i < MAX; i++) 
        for (int j = i; j < MAX; j += i)
            factors[j].push_back(i);

    int t; cin >> t;
    while (t--)
        solve();
}