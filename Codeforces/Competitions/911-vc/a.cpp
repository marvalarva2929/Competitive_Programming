#include <bits/stdc++.h>
#define int long long
#define nl " \n"
#define pi pair<int, int>
#define ff first
#define ss second

using namespace std;

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    
    int t = 0;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '.') cnt++, t++;
        else cnt = 0;
         
        if (cnt >= 3) { cout << 2 << nl; return; }
    }
    
    cout << t << nl;
    return;
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t; cin >> t;
    while (t--)
        solve();
}
