#include <bits/stdc++.h>
#define int long long
#define pi pair<int, int>
#define x first
#define y second
#define nl " \n"

using namespace std;
const int mxn = 2e5;
pi pref[mxn+1], suf[mxn+1];
string s;
int n, q; 

void solve() {
    cin >> n >> q >> s;
    map<pi, int> ff, ss;
    
    ff[{0, 0}] = ss[{0, 0}] = 0;

    for (int i = 0; i < n; i++) {
        int dx = (s[i] == 'R' ? 1 : s[i] == 'L' ? -1 : 0),
            dy = (s[i] == 'U' ? 1 : s[i] == 'D' ? -1 : 0);         
        
        pref[i + 1].x = pref[i].x + dx;
        pref[i + 1].y = pref[i].y + dy;
        
        if (!ff[pref[i + 1]] && (pref[i + 1].x != 0 || pref[i + 1].y != 0)) ff[pref[i + 1]] = i + 1; 
        ss[pref[i + 1]] = i + 1;
    }
    
    for (int i = n - 1; i >= 0; i--) {
        int dx = (s[i] == 'R' ? 1 : s[i] == 'L' ? -1 : 0),
            dy = (s[i] == 'U' ? 1 : s[i] == 'D' ? -1 : 0);         
        
        suf[i + 1].x = (i < n - 1 ? suf[i + 2].x : 0) + dx;
        suf[i + 1].y = (i < n - 1 ? suf[i + 2].y : 0) + dy;
    }

    vector<pair<pi, pi>> xylr(q);
    for (int i = 0; i < q; i++) {
        int xx, yy, l, r; cin >> xx >> yy >> l >> r; 
        xylr[i] = {{xx, yy}, {l, r}}; 
    }
        
    //if (n == 100) {
    //    cout << xylr[52].x.x << '-' << xylr[52].x.y << '-' << xylr[52].y.x << '-' << xylr[52].y.y << nl;
    //}
    
    vector<int> ord(q); iota(ord.begin(), ord.end(), 0);
    
    sort(ord.begin(), ord.end(), [&xylr](const int & a, const int & b) -> bool {
                return xylr[a].y.x > xylr[b].y.x; 
            });
    
    

    vector<int> ans(q, -1);
    map<pi, int> pos;
    int cur = n;
    //cout << nl;
    
    //for (int i = 66; i<= 100; i++)
    //    if (suf[i].x == 0 && suf[i].y == 0) cout << " ----- " << i << nl;

    for (int ii = 0; ii < q; ii++) { 
        int i = ord[ii];
        pi xy = xylr[i].x;
        int l = xylr[i].y.x, r = xylr[i].y.y;
         
        //cout << i << " : " << xy.x << " " << xy.y << " " << l << " " << r << nl;
        //cout << ff[xy] << " " << ss[xy] << nl << nl;

        if (xy.x == 0 && xy.y == 0) ans[i] = 1;
        else if (((ff[xy] < l && ff[xy]) || ss[xy] >= r) || (ss[xy] && ss[xy] < l) || (ff[xy] >= r)) ans[i] = 1;
        else {
            while (cur >= l) 
                pos[suf[cur]] = cur, cur--;

            pi need = {xy.x - pref[l - 1].x + suf[r + 1].x,
                        xy.y - pref[l - 1].y + suf[r + 1].y};
            
            //cout << pref[l - 1].x << " " << suf[r + 1].x << " : " << pref[l - 1].y << " " << suf[r + 1].y << nl;
            //cout << need.x << " " << need.y << " : " << pos[need] << nl;

            ans[i] = (pos[need] != 0 && pos[need] <= r);
        }
        //cout << nl;
    }
    
    for (int i = 0; i < q; i++)
        cout << (ans[i] == 1 ? "YES" : ans[i] == -1 ? " alsdjf;alsd" : "NO") << nl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t = 1; 
    while (t--)
        solve();
}
