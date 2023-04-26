#include <bits/stdc++.h>
#include <string.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi; 
typedef vector<pair<int,int>> vpi; 

#define pb push_back
#define int long long
#define nl '\n'
#define rsz resize
#define sz(x) int(x.size())
#define all(x) begin(x), end(x)
#define f first
#define s second

void solve() {
    int k;
    string x;
    cin >> x >> k;
    vector<vector<int>> pos(10);
    for (int i = 0; i < x.size(); i++) pos[x[i] - '0'].pb(i);
    for (int i = 0; i < pos.size(); i++)
        reverse(pos[i].begin(), pos[i].end());
    int lst = 0;
    string ans;
    int len = x.size() - k;
    for (int i = 0; i < len; i++) {
        for (int j = (i == 0); j <= 9; j++) {
            // cout << j << ": " << pos[j].empty() << nl;
            while (!pos[j].empty() && pos[j].back() < lst) {
                // cout << j << ": " << pos[j].back() << nl;
                pos[j].pop_back();
            }
            if (!pos[j].empty() && (pos[j].back() - lst) <= k) {
                // cout <<pos[j].back() << ": " << j << ": " << i << ": " << lst << ": " << k << nl;
                k -= (pos[j].back() - lst);
                lst = pos[j].back() + 1;
                ans +=  j + '0';
                // cout << ans << nl;
                break;
            }
        }
    }
    cout << ans << nl;
}

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }    
}
