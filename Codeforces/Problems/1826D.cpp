#include <bits/stdc++.h>
#define int long long
#define pi pair<int, int>
#define ff first
#define ss second
#define nl " \n"

using namespace std;
const int mxn = 1e5;
int a[mxn], h[mxn];
pi b[mxn];

void solve() {
    int n; cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i], b[i].ff = a[i], b[i].ss = i;
    
    sort(b, b + n, greater<int>());
    for (int i = 0; i < n; i++)
        h[i] = b[i].ss;
           
    for (int i = 0; i < n; i++)
        cout << h[i] << nl[i == n -1];
    return;
    
    set<int> cur;
    int s = 0;
    for (int i = 0; i < 3; i++)
        cur.insert(h[i]), s += a[h[i]];
    int ans = s - ((*(--cur.end())) - (*cur.begin()));
    //cout << ans << nl;;

    for (int i = 3; i < n; i++) {
        cur.insert(h[i]);
        auto bf = (cur.find(h[i]));
        if (bf == cur.begin()) {
            int s = a[*bf];
            s += a[*(++bf)];
            s += a[*(++bf)];
        
            int l = *bf - *cur.begin();

            ans = max(ans, s - l);
        } else if (bf == (--cur.end())) {
            int s = a[*bf];
            s += a[*(--bf)];
            s += a[*(--bf)];
        
            int l = *(--cur.end()) - *bf;

            ans = max(ans, s - l);
        } else {
            //cout << i << " : " << nl;
            auto lf = bf, rf = bf; --lf, ++rf;

            int s = a[*bf] + a[*lf] + a[*rf];
            int l = *rf - *lf;
            
            ans = max(ans, s - l);
            //cout << 'c' << " " << *bf << " " << *lf << " " << *rf << nl;

            if (lf != cur.begin()) {
                --lf;
                s -= a[*rf] - a[*lf];
                l = *bf - *lf;
                ans = max(ans, s - l);
                //cout << "r " << ans << nl; 
            }
            if (rf != --cur.end()) {
                ++rf;
                s -= a[*lf] - a[*rf];
                l = *rf - *bf;
                ans = max(ans, s - l);
                //cout << "l " << ans << nl;
            } 
        }
    }

    cout << ans << nl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t; cin >> t;
    while (t--)
        solve();
}
