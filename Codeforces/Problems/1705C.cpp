using namespace std;
#include <bits/stdc++.h>
#define int long long
#define nl '\n'
#define MAX (int)8e6 + 10

int n; string s;
vector<pair<int, int>> at;

char charOf(int i) {
    int j = at.size() - 1;
    while (i >= n) {
        while (at[j].first > i && j >= 0)
            j--;
        i -= at[j].second;
    }
    return s[i];
}

void solve() {
    int c, q; cin >> n >> c >> q;
    cin >> s;
    at.clear();

    int curr = n;

    for (int i = 0; i < c; i++) {
        int l, r; cin >> l >> r;
        --l, --r;
        at.push_back({curr, curr - l});
        curr += (r - l) + 1;
    }

    for (int i = 0; i < q; i++) {
        int x; cin >> x;
        cout << charOf(--x) << nl;
    }

}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t; cin >> t;
    while (t--)
        solve();
}