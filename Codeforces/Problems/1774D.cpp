using namespace std;
#include <bits/stdc++.h>
#define int long long
#define nl '\n'
#define pi pair<int, int>
#define vi vector<int>
#define vpi vector<pi>

void solve() {
    int n, m; cin >> n >> m;
    vector<pair<pi, int>> ans;

    int grid[n][m] = {};
    queue<int> more, less;
    int inrow[n];
    int ones = 0;

    for (int i = 0; i < n; i++) {
        int temp = 0;
        for (int j = 0; j < m; j++) 
            cin >> grid[i][j], temp += (grid[i][j] == 1);
        inrow[i] = temp;
        ones += temp;
    }

    if (ones % n) {
        cout << -1 << nl;
        return;
    } 
    
    for (int i = 0; i < n; i++) 
        inrow[i] -= ones/n;
    
    for (int i = 0; i < m; i++) {
        vector<int> from, to;
        for (int j = 0; j < n; j++) {
            if (inrow[j] > 0 && grid[j][i]) from.push_back(j);
            if (inrow[j] < 0 && !grid[j][i]) to.push_back(j);
        }

        for (int k = 0; k < min((int)from.size(), (int)to.size()); k++) {
            inrow[from[k]]--, inrow[to[k]]++;
            ans.push_back({{from[k], to[k]}, i});
            swap(grid[from[k]][i], grid[to[k]][i]);
        }        
    }   

    cout << ans.size() << nl;

    for (auto p : ans)
        cout << p.first.first + 1 << " " << p.first.second + 1<< " " << p.second + 1<< nl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t; cin >> t;
    while (t--)
        solve();
}