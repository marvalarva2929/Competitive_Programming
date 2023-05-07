using namespace std;
#include <bits/stdc++.h>
#define int long long
#define nl '\n'
#define MAX (int)2e5 + 10
#define print(x) for (auto i : x) { cout << i << " "; } cout << nl;
int h[MAX];
int n;

bool can(int x) {
    vector<int> c_h(h, h + n);
    for (int i = n - 1; i >= 2; i--) {
        if (c_h[i] < x) return false;
        else {
            int d = min(h[i], c_h[i] - x) / 3;
            c_h[i - 1] += d;
            c_h[i - 2] += d * 2; 
        }
    }
    return (c_h[0] >= x && c_h[1] >= x);
}

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> h[i];
    
    int l = 1, r = *max_element(h, h + n);

    while (l < r) {
        int m = l + (r - l + 1) /2;
        if (can(m)) l = m;
        else r = m - 1;
    }
    cout << l << nl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t; cin >> t;
    while (t--)
        solve();
}