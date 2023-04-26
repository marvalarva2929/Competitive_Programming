using namespace std;
#include <bits/stdc++.h>
#define int long long
#define nl '\n'
#define MAX(int)5e4 + 10

int sim(const vector<int> & a, const vector<int> & b) {
    int i = 0;
    while (i < (int)a.size() && a[i] == b[i])
        i++;
    return i;
}

void solve() {
    int n, m; cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m));
    vector<vector<int>> inverses(n, vector<int>(m));
    int ans[n] = {};

    for (int i = 0; i < n; i++) 
        for (int j = 0; j < m; j++)
            cin >> grid[i][j], 
            grid[i][j]--;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            inverses[i][grid[i][j]] = j;
    
    sort(inverses.begin(), inverses.end());

    for (int i = 0; i < n; i++) {
        vector<int> perm = grid[i];

        int j = lower_bound(inverses.begin(), inverses.end(), perm) - inverses.begin();
        int c_ans = 0;
        if (j > 0) c_ans = max(c_ans, sim(perm, inverses[j - 1]));
        if (j < n) c_ans = max(c_ans, sim(perm, inverses[j]));
        ans[i] = c_ans; 
    }

    for (int i : ans)
        cout << i << " ";
    cout << nl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t; cin >> t;
    while (t--)
        solve();
}