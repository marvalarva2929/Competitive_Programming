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
#define MAX (int)3e5 + 10
int a[MAX];
int n;

bool ishv(int x) {
    if (x >= n -1 || x < 1) return 0;
    return ((a[x] > a[x - 1] && a[x] > a[x + 1]) || (a[x] < a[x - 1] && a[x] < a[x + 1]));
}

void solve() {
    unordered_map<int, int> hv;
    int intim = 0;

    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> a[i];

    for (int i = 1; i < n - 1; i++)
        if ((a[i] < a[i - 1] && a[i] < a[i + 1]) || (a[i] > a[i - 1] && a[i] > a[i + 1]))
            hv[i] = 1, intim++;

    int ans = intim;
    for (int i = 1; i < n - 1; i++) {
        int t = a[i];
        a[i] = a[i + 1];
        ans = min(ans, intim - hv[i] - hv[i - 1] - hv[i + 1] + ishv(i - 1) + ishv(i) + ishv(i + 1));
        a[i] = a[i - 1];
        ans = min(ans, intim - hv[i] - hv[i - 1] - hv[i + 1] + ishv(i - 1) + ishv(i) + ishv(i + 1));
        a[i] = t;
    }
    cout << ans << nl;
    
}

int32_t main() {
    int t; cin >> t;
    while (t--)
        solve();
} 