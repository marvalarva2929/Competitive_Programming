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
    int n; string s; cin >> n >> s;
    int o = 0;
    
    s = s.substr(1, s.size());

    for (char c : s)
        if (c&1) 
            cout << ((o++ % 2) ? '+' : '-');
        else cout << '+';
    cout << nl;
        



}

int32_t main() {
     cin.tie(0)->sync_with_stdio(false);

    int t; cin >> t;
    while (t--)
        solve();
} 