using namespace std;
#include <bits/stdc++.h>
#include <string.h>
typedef long long ll;
typedef vector<int> vi;
typedef vector<pair<int,int>> vpi;
#define pb push_back
#define int long long
#define nl '\n'
#define rsz resize
#define sz(x) int(x.size())
#define all(x) begin(x), end(x)
#define no "no"
#define yes "yes"
#define print(x, y, z) for (int i = y; i <= z; i++) {cout << x[i] << " ";} cout << nl;

void solve() {
    int n, k; cin >> n >> k;
    int curr = n;
    int iter = 0;
    int a[n] = {};

    int iter2 = 0;
    for (int i = 0; i < n; i++) {
        a[i] = curr - iter2++;
        iter++;
        if (iter == k - 1) i += k - 1, iter = 0;
    }
    int iter3 = 1;
    for (int i = 1; i < n; i++) {
        if (!a[i])
            a[i] = iter3++;
    }
    print(a, 0, n -1);
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    while (t--)
        solve();
} 