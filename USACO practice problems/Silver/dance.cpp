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
#define no "no"
#define yes "yes"
#define print(x, y, z) for (int i = y; i <= z; i++) {cout << x[i] << " ";} cout << nl;
#define MAX (int)1e5 + 10
#define MAX2 (int)2e5 + 10
int cowAt[MAX];
int finalPos[MAX];
int ans[MAX];
pair<int, int> moves[MAX2];
set<int> visited[MAX];

int32_t main() {
    int n, k;
    cin >> n >> k;
    iota(cowAt, cowAt + n + 1, 0);

    for (int i = 0; i < k; i++) {
        int a, b; cin >> a >> b;
        moves[i] = {a, b};
    }   


    for (int i = 0; i < k; i++) {
        auto move = moves[i];
        visited[cowAt[move.first]].insert(move.first);
        visited[cowAt[move.second]].insert(move.second);
        swap(cowAt[move.first], cowAt[move.second]);
    }

    for (int i = 1; i <= n; i++) {
        finalPos[cowAt[i]] = i;
        visited[i].insert(i);
    }
    
    vector<int> vis(n + 1, 0);
    // cout << 'e' << nl;
    // print(finalPos, 0, 1 + n);
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            set<int> wv;
            merge(visited[i].begin(), visited[i].end(), wv.begin(), wv.end(), inserter(wv, wv.begin()));
            set<int> toFix;
            vis[i] = true;
            int j = finalPos[i];
            // cout << i << ": " << visited[i].size() << nl;
            while (j != i) {
                // cout << j << nl;
                vis[j] = true;
                toFix.insert(j);
                merge(visited[j].begin(), visited[j].end(), wv.begin(), wv.begin(), inserter(wv, wv.begin()));
                j = finalPos[j];
            }
            // cout << nl;
            ans[i] = wv.size();
            for (int fix : toFix)
                ans[fix] = wv.size();
        }
    }
    for (int i = 1; i <= n; i++)
        cout << ans[i] << nl;
} 