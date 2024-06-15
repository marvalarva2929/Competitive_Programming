#include <bits/stdc++.h>
#define int long long
#define nl " \n"
#define pi pair<int, int>
#define ff first
#define ss second

using namespace std;
const int mxn = 3e5;
int a[mxn+2], d[mxn+2];

void solve() {
    int n; cin >> n;
    a[n + 1] = a[0]  = 0;
    d[n + 1] = d[0] = 0; 
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        cin >> d[i];

    set<int> check, in;
    in.insert(0);
    for (int i = 1; i <= n; i++)
        check.insert(i), in.insert(i);
    in.insert(n + 1); 
    
    for (int o = 0; o < n; o++) {
        set<int> ncheck, nin;
        int cnt = 0;
        //cout << o << " : " << nl;
        for (int c : check) {
            auto it = in.find(c); 
            if (it == in.end()) continue;
            int l = *prev(it), r = *next(it);
            
            if (a[l] + a[r] > d[c]) {
                cnt++;
                nin.insert(c);
                //cout << c << nl;
                if (l) ncheck.insert(l);
                if (r <= n) ncheck.insert(r);
            }
        }
        check = ncheck;
        for (int c : nin)
            in.erase(c);
        cout << cnt << nl[o == n - 1];
    }
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t; cin >> t;
    while (t--)
        solve();
}
