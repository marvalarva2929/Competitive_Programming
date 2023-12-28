#include <bits/stdc++.h>
#define int long long
#define pi pair<int, int>
#define ff first
#define ss second
#define nl " \n"

using namespace std;
int dx[2] = {-1, 1};
int dy[2] = {-1, 1};

void solve() {
    int a, b; cin >> a >> b;
    pi ki, q; cin >> ki.ff >> ki.ss >> q.ff >> q.ss;
    
    set<pi> poss;
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            for (int k = 0; k < 2; k++) {
                pi pos = { 
                    ki.ff + (dx[j] * (i ? a : b)), ki.ss + (dy[k] * (i ? b : a)) };
                poss.insert(pos);
            }
    
    int ans = 0;
    
    set<pi> p2;
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            for (int k = 0; k < 2; k++) {
                pi pos = { 
                    q.ff + (dx[j] * (i ? a : b)), q.ss + (dy[k] * (i ? b : a)) };
                p2.insert(pos); 
            }
    
    for (pi x : poss) ans += p2.count(x);

    cout << ans << nl;

}
signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t; cin >> t;
    while (t--)
        solve();
}
