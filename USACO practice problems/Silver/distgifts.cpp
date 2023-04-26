using namespace std;
#include <bits/stdc++.h>
#include <string.h>
#include <algorithm>
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
#define adjacency_list vector<vector<int>>
#define set2d set<vector<int>>
#define MAX 5000
vector<int> pref[MAX];
int prior[MAX][MAX]; // priority

class Strong_Connected_Components {
    private:
    adjacency_list reverse;
    adjacency_list main;
    vector<int> finishing_times;
    vector<int> visited;
    int size;
    public:
    Strong_Connected_Components(adjacency_list rev, adjacency_list m, int n) {
        finishing_times.resize(m.size());
        visited.resize(m.size());
        reverse = rev;
        size = n;
        main = m;
    }

    vector<int> dfs(int i, bool reversed) {
        vector<int> thi = {i};
        vector<int> ret = {i};
        if (reversed) {
            if (!visited[i]) {
                visited[i] = true;
                for (int adj : reverse[i]) {
                    if (!visited[adj]) 
                        dfs(adj, true);
                }
            }
        finishing_times.push_back(i);
        } else {
            if (!visited[i]) {
                visited[i] = true;
                for (int adj : main[i]) {
                    if (!visited[adj]) {
                        vector<int> mer = dfs(adj, false);
                        for (int a : mer) ret.push_back(a);
                    }
                }
            } 
        }
        return ret;
    }

    set2d find() {
        fill(visited.begin(), visited.end(), 0);
        for (int i = 1; i < size; i++) {
            if (!visited[i]) {
                // cout << i << nl;
                dfs(i, true);
            }
        }
        // cout << 'e' << nl; 
        std::reverse(finishing_times.begin(), finishing_times.end());
        // print(finishing_times, 0, size);
        set2d ans;
        fill(visited.begin(), visited.end(), false);
        for (int finish : finishing_times) {
            if (finish == 0) continue;
            if (!visited[finish]) {
                vector<int> toAdd = dfs(finish, false);
                ans.insert(toAdd);
            } 
        }

        return ans;
    }

};

int32_t main() {
    int n;
    cin >> n;
    vector<int> ans(n + 1);
    iota(ans.begin(), ans.end(), 0);
    for (int i = 1; i <= n; i++)
        for (int j = 0; j < n; j++) {
            int num; cin >> num;
            pref[i].push_back(num);
            prior[i][num] = j;
            prior[i][i] = INT_MAX;
        }

    adjacency_list m(MAX);
    adjacency_list rev(MAX);

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < n; j++) {
            m[i].push_back(i);
            rev[i].push_back(i);
            if (pref[i][j] != i) {
                // cout << i << "adj to " << pref[i][j] << nl;
                m[i].push_back(pref[i][j]);
                rev[pref[i][j]].push_back(i);
            } else break;
        }
    }
    Strong_Connected_Components SCC(rev, m, n + 1);

    // for (auto a : SCC.find()) {
    //     for (auto b : a) {
    //         cout << b << " ";
    //     }
    //     cout << nl;
    // }

    for (vector<int> scc : SCC.find()) {
        for (int i = 0; i < scc.size(); i++) {
            for (int j = 0; j < scc.size(); j++) {
                if (j == i) continue;
                if (prior[scc[i]][scc[j]] < prior[scc[i]][ans[scc[i]]]) {
                    ans[scc[i]] = scc[j];
                }
            }
        }
    }
    
    for (int i = 1; i <= n; i++)
        cout << ans[i] << nl;
}