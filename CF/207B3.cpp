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
#define print(x, y, z) for (int i = y; i <= z; i++) {cout << x[i] << " ";} cout << nl;
#define adjList vector<vector<int>>

int bfs(adjList adj, int s, int t) {
    queue<pair<int, int>> nextNode;
    nextNode.push({s, 0});
    vector<bool> visited(adj.size());
    while (!nextNode.empty()) {
        auto next = nextNode .front();
        // cout << next.first<< ": " << next.second << nl;
        if (next.first == t) {
            return next.second; 
        }
        nextNode.pop();
        if (!visited[next.first]) {
            visited[next.first] = true;
            for (int a : adj[next.first]) 
                if (!visited[a]) {
                    // cout << next.first << " to " << a << nl;
                    nextNode.push({a, next.second + 1});
                }
        }
    }
}

int32_t main() {
    int n;
    cin >> n;
    vector<int> nums(n);    
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    vector<int> rnums(nums.begin(), nums.end());
    for (int i = 0; i < n - 1; i++) {
        for (int r : rnums)
            nums.push_back(r);
    }
   
    print(nums, 0, n * n - 1);
    int ans = 0;
    vector<int> temp;
    for (int i = 0; i < n * (n - 1); i += n - 1) {
        adjList adj(n * n, temp);
        cout << n + i - 1 << " to " << i << " -- " << nums[n + i - 1]<< ", " << nums[i] << nl;
        for (int j = i + n - 1; j > i;) {
            adj[j].push_back(max(i, j - nums[j]));
            cout << j << ": " << max(i, j - nums[j]) << nl;
            j -= nums[j];
        }
        ans += bfs(adj, i + n - 1, i);
    }
    //TODO: DON;T DO BFS, JUST
    cout << ans << nl;
} 