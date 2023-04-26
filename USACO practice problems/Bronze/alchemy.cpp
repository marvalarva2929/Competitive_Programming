using namespace std;
#include <bits/stdc++.h>
#define int long long
#define nl '\n'
#define MAX (int)100 + 10

int a[MAX] = {};
vector<int> b[MAX] = {};
unordered_map<int, int> cache;

bool canMake(int i) {
    if (a[i] > 0) {
        a[i]--;
        return true;
    }
    if (b[i].empty()) return false;
    for (int recipe : b[i]) if (!canMake(recipe)) return false;
    return true;
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);
    int n; cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int k; cin >> k;

    for (int i = 0; i < k; i++) {
        int l, m; cin >> l >> m;
        for (int j = 0; j < m; j++) {
            int x; cin >> x;
            b[l - 1].push_back(x - 1);
        }
    }

    int ans = 0;
    while (canMake(n - 1)) ans++;
    cout << ans << nl;
}