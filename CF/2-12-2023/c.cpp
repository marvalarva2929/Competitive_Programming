using namespace std;
#include <bits/stdc++.h>
#define int long long
#define nl '\n'
#define no "no"
#define yes "yes"
#define print(x, y, z) for (int i = y; i <= z; i++) {cout << x[i] << " ";} cout << nl;

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

void solve() {
    int n; cin >> n;
    int mx = n, mn = 1;
    unordered_map<int, bool, custom_hash> ex;
    int a[n] = {};
    for (int i = 0; i < n; i++)
        cin >> a[i];
    
    int i = 0, j = n - 1;
    while (i < j) {
        if ((a[i] != mx && a[i] != mn) && a[j] != mx && a[j] != mn)
            break;
        else {
            while (i < n && a[i] == mn) {
                ex[a[i]] = true;
                i++;
                while (ex[mn]) mn++;
            }
            while (i < n && a[i] == mx) {
                ex[a[i]] = true;
                i++;
                while (ex[mx]) mx--;
            }
            while (j >= 0 && a[j] == mn) {
                ex[a[j]] = true;
                j--;
                while (ex[mn]) mn++;
            }
            while (j >= 0 && a[j] == mx) {
                ex[a[j]] = true;
                j--;
                while (ex[mx]) mx--;
            }
            // cout << i << " " << j << " " << a[j] << " " << a[i] << nl;
        }
    }
    if (i < j) cout << i + 1 << " " << j + 1 << nl;
    else cout << -1 << nl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t; cin >> t;
    while (t--)
        solve();
}