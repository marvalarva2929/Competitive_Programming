#include <bits/stdc++.h>
#define int long long
#define nl '\n'
#define pi pair<int, int>
#define ff first
#define ss second

using namespace std;
const int mxn = 2e5;

pi a[mxn];
int n;

pi getDims() {
    set<pi> widths, heights;
    pi ans = {-1, -1};

    for (int i = 0; i < n; i++)
        widths.insert({a[i].second, i}),
        heights.insert({a[i].first, i});

    int prevh = INT_MAX, prevw = INT_MAX;
    int prv = 0;

    bool mode = 1;
    bool first = 1;

    while (widths.size()) {
        if (mode) {
            int cur = (*widths.rbegin()).ff, sum = 0;
            if (ans.ss == -1) ans.ss = cur;

            while (widths.size() && (*widths.rbegin()).ff == cur) {
                auto it = (--widths.end());
                heights.erase({a[it->ss].ff, it->ss});
                sum += a[it->ss].ff;
                widths.erase(it);
            }

            if (first) ans.ff = sum;
            prv = sum;

            if (prevh == INT_MAX) {
                prevw = cur;
            } else { 
                prevh -= sum;
                if (prevw != cur) return {-1, -1}; 
            }
        } else {
            int cur = (*heights.rbegin()).ff, sum = 0;
            
            if (first) {
                ans.ff = cur + prv;
                first = 0;
            }

            while (heights.size() && (*heights.rbegin()).ff == cur) {
                auto it = (--heights.end());
                widths.erase({a[it->ss].ss, it->ss});
                sum += a[it->ss].ss;
                heights.erase(it);
            }
            
            prevw -= sum;
            if (prevh == INT_MAX) 
                prevh = cur;
            
            if (prevh != cur) {
                return {-1, -1};
            }
        }

        mode = !mode;
    }
    
     
    if (prevw == INT_MAX || prevh == INT_MAX || prevh == 0 || prevw == 0)
        return ans;
    else return {-1, -1};
}

void solve() {
    cin >> n;
    int mxh = 0, mxw = 0;

    for (int i = 0; i < n; i++) 
        cin >> a[i].ff >> a[i].ss;
         
    vector<pi> ans;
    ans.push_back(getDims());
    if (ans.back().ff == -1)
        ans.pop_back();

    for (int i = 0; i < n; i++)
        swap(a[i].ff, a[i].ss);
    
    ans.push_back(getDims());
    swap(ans.back().ff, ans.back().ss);
    if (ans.back().ff == -1)
        ans.pop_back();

    if (ans[0] == ans[1])
        ans.pop_back();
   
    cout << ans.size() << nl;
    for (pi x : ans)
        cout << x.ff << " " << x.ss << nl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t; cin >> t;
    while (t--)
        solve();
}
