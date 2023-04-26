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
    int n, m;  cin >> n >> m;
    int a[n] = {};
    int b[m] = {};
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < m; i++)
        cin >> b[i];

    sort(a, a + n);

    for (int i = 0; i < m; i++) {
        sort(a, a + n);
        for (int j = 0; j < n; j++) {
            int changed = false;
            if (a[j] < b[i]) {
                a[j] = b[i], changed = true; 
                // print(a, 0, n -1);
                // cout << "changed " << j << " to " << b[i] << nl;
                break;
            }

            if (!changed)
                a[0] = b[i];
        }
    }
        
    int ans = 0;
    for (int i = 0; i < n; i++)
        ans += a[i];
    // print(a, 0, n -1 );
    cout << ans << nl;
    
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while (t--)
        solve();
} 