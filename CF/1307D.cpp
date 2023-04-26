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
#define MAX (int)200500
vector<int> adj[MAX];
int order[MAX];
int inorder[MAX];
bool visited[MAX];
vector<int> ans;

void bfs(int i) {
    queue<int> q;
    q.push(i);
    while (!q.empty()) {
        queue<int> temp;
        while (!q.empty()) {
            int x = q.front();
            q.pop();
            if (!visited[x]) {
                ans.push_back(x);
                visited[x] = true;
                for (int next : adj[x]) 
                    if (!visited[next])
                        temp.push(next);
            }
        }
        q = temp;
    }
}

int32_t main() {
    int n;
    cin >> n;
    vector<int> ft;
    for (int i = 0; i < n - 1; i++) {
        int to, from; cin >> from >> to;
        adj[from].push_back(to);
        adj[to].push_back(from);
    }
    for (int i = 0; i < n; i++) {
        int num; cin >> num;
        inorder[i] = num;
        order[num] = i;
    }

    for (int i = 0; i <= n; i++) {
        sort(adj[i].begin(), adj[i].end(), [](int a, int b) -> bool {
            return order[a] < order[b];
        });
    
    }
    bfs(1);
    // print(visited, 0, n);
    // print(order, 0, n);
    for (int i = 0; i < n; i++) {
        if (ans[i] != inorder[i]) {
            cout << no << nl;
            return 0;
        }
    }

    cout << yes << nl;
    return 0;
} 
