#include <bits/stdc++.h>
#define int long long
#define nl " \n"
#define pi pair<int, int>
#define ff first
#define ss second

using namespace std;
const int mxn = 2e5;
bool a[mxn];

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    int cnt = 0;

    for (int i = 0; i < n; i++)
        a[i] = s[i] & 1, cnt += a[i];

    if (cnt == 0 || cnt % 2) {
        cout << "NO" << nl;
        return;
    }
    
    cout << "YES" << nl;

    vector<int> segs;
    vector<pi> ans;

    for (int i = 1; i < n; i++)
        if (a[i - 1] == 1) {
            int last = i;
            for (int j = i; j < i + n; j++) {
                if (j % n != last) ans.emplace_back((j - 1) % n, j % n);
                if (a[j % n] == 1) segs.push_back(last), last = (j + 1) % n;
            }
            break; 
        } 
    
    bool good = 0;
    for (int x : segs) {
        if (!a[x]) {
            for (int y : segs)
                if (y != x)
                    ans.emplace_back(x, y);
            good = 1; 
            break;
        }
    }
   
    
        
    if (!good) {
        int x = segs[0]; 
        for (int y : segs)
            if (y != x)
                ans.emplace_back(x, y);
    }
    
    for (pi& y : ans)
        cout << y.ff + 1 << " " << y.ss + 1 << nl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t; cin >> t;
    while (t--)
        solve();
}
