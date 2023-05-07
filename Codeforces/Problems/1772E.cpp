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
#define MAX (int)5e5 + 10
int a[MAX];

void solve() {
    int n; cin >> n;
    int x = 0, y = 0, z = 0;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        bool ab = a[i] != i + 1;
        bool ac = a[i] != n - i;

        if (ab && ac) z++;
        else if (ab) x++;
        else if (ac) y++;
    }

    if (x + z <= y)
        cout << "First" << nl;
    else if (y + z < x)
        cout << "Second" << nl;
    else 
        cout << "Tie" << nl;
    
    return;    
}

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    int t; cin >> t;
    while (t--)
        solve();

    return 0;
} 