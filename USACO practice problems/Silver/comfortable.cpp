using namespace std;
#include <bits/stdc++.h>
#include <string.h>
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
#define print(x, y, z) for (int i = y; i <= z; i++) {cout << x[i] << " ";} cout << nl;
#define MAX (int)3e3 + 10
const int dx[4] = {0, -1, 0, 1}, dy[4] = {1, 0, -1, 0};
int allCows = 0;
int grid[MAX][MAX];
map<pair<int, int>, bool> cowAt;

int32_t main() {
    int n;
    cin >> n;
    vector<int> cx(n);
    vector<int> cy(n);
    int mx = 0, my = 0;
    queue<pair<int, int>> toCheck;
    for (int i = 1; i <= n; i++) {
        int x, y; cin >> x >> y;
        x += 501, y += 501;
        auto check = [&](int p, int q) {
            if (!grid[p][q]) return;
            int adj = 0;
            for (int d = 0; d < 4; d++)
                if (grid[p + dx[d]][q + dy[d]])
                    adj++;
            // cout << p - 501<< ", " << q-501 << " -- " << adj << nl;
            if (adj == 3) {
                for (int d = 0; d < 4; d++) 
                    if (!grid[p + dx[d]][q + dy[d]]) {
                        toCheck.push({p + dx[d], q + dy[d]});
                    }
            }
        };
        toCheck.push({x, y});
        while (!toCheck.empty()) {
            auto next = toCheck.front();
            toCheck.pop();
            if (grid[next.first][next.second]) continue;
            allCows++;
            // cout << "added cow at " << next.first - 501 << ", " << next.second -501 << nl;
            grid[next.first][next.second] = 1;
            check(next.first, next.second);
            for (int d = 0; d < 4; d++)
                check(next.first + dx[d], next.second + dy[d]);
        }
        // cout << i << ": " << allCows << nl;
        cout << allCows - i << nl;
    }
    // cout << nl;
    // for (int i = 501; i < 506; i++) {
    //     for (int j = 501; j < 506; j++)
    //         cout << grid[i][j] << " ";
    //     cout << nl;
    // }
    // cout << nl;
}
