using namespace std;
#include <bits/stdc++.h>
#define int long long
#define nl '\n'
#define MAX (int)2e5 + 10

bool isSorted(vector<int> check) {
    for (int i = 1; i < check.size(); i++)
        if (check[i - 1] > check[i])
            return false;
    return true;
}

void solve() {
    int n, m; cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m));

    for (int i = 0; i < n; i++) 
        for (int j = 0; j < m; j++) 
            cin >> grid[i][j];



    vector<int> bad;
    for (int i = 0; i < n && bad.empty(); i++) {
        vector<int> b = grid[i];
        sort(b.begin(), b.end());
        for (int j = 0; j < m; j++)
            if (b[j] != grid[i][j]) bad.push_back(j);
    }

    if ((int)bad.size() > 2) {
        cout << -1 << nl;
        return;
    } 

    if (!(int)bad.size()) { cout << 1 << " " << 1 << nl; return; }

    for (int i = 0; i < n; i++)
        std::swap(grid[i][bad[0]], grid[i][bad[1]]);

    for (int i = 0; i < n; i++)
        if(!isSorted(grid[i])) {
            cout << -1 << nl;
            return;
        }
        
    cout << bad[0] + 1 << " " << bad[1] + 1 << nl;
    return;
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t; cin >> t;
    while (t--)
        solve();
    return 0;
}