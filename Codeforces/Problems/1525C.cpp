#include <bits/stdc++.h>
#define int long long
#define nl " \n"
#define pi pair<int, int>
#define ff first
#define ss second

using namespace std;
const int mxn = 3e5;
int a[mxn], ans[mxn], t[mxn];
bool dir[mxn];

void solve() {
    int n, m; cin >> n >> m;
    
    for (int i = 0; i < n; i++)
        cin >> a[i];
    
    iota(t, t + n, 0);
    sort(t, t + n, [](const int& i, const int& j) -> bool {
            return a[i] < a[j]; 
            });

    for (int i = 0; i < n; i++) { 
        char c; cin >> c;
        dir[i] = c == 'R';
    }
    
    int nil = t[0];
    int bc = t[n - 1];

    //if (!dir[nil]) a[nil] = -a[nil], dir[nil] = 1;
    //if (dir[bc]) a[bc] = m + (m - a[bc]), dir[bc] = 0;


    for (int j = 0; j < 2; j++) {
        stack<int> right;
        vector<int> lo;

        for (int ti = 0; ti < n; ti++) {
            int i = t[ti];
            
            if (abs((int)a[i] % 2) == j) {
                if (dir[i]) right.push(i);
                else if (right.size()) {
                    int prv = right.top();
                    right.pop();
                    ans[prv] = ans[i] = (a[i] - a[prv])/2;
                } else lo.push_back(i);
            }
        }
        
        int prv = -1;
        for (int i = 0; i < lo.size(); i++) {
            if (prv == -1) prv = lo[i];
            else {
                int cur = lo[i];
                int l = -a[prv];
                ans[cur] = ans[prv] = (a[cur] - l)/2;
                prv = -1;
            }
        }
        
        int lastL = -1;
        if (prv != -1) ans[prv] = -1, lastL = prv;
        prv = -1; 
        
        while (right.size()) {
            if (prv == -1) prv = right.top();
            else {
                int cur = right.top();
                int l = m + m - a[prv];
                ans[cur] = ans[prv] = (l - a[cur])/2;
                prv = -1;
            }
            right.pop();
        }
        
        int lastR = -1;
        if (prv != -1) ans[prv] = -1, lastR = prv;
    
        if (lastL != -1 && lastR != -1) {
            int l = -a[lastL], r = m + m - a[lastR];
            ans[lastL] = ans[lastR] = (r - l)/2;
        }
    }

    for (int i = 0; i < n; i++)
        cout << ans[i] << nl[i == n -1];
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t; cin >> t;
    while (t--)
        solve();
}
