using namespace std;
#include <bits/stdc++.h>
#define int long long
#define nl '\n'
vector<int> adj[(int)4e5 + 10];
int removals[(int)4e5 + 10];

struct Node {
    int i;
    int depth;
};

void solve() {
    int n, k; cin >> n >> k;
    fill(adj, adj + n, vector<int>());
    fill(removals, removals + k + 1, 0);

    for (int i = 1; i < n; i++) {
        int a, b; cin >> a >> b;
        --a, --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    queue<Node> q;
    int children_removed[n] = {};
    for (int i = 0; i < n; i++) {
        if (adj[i].size() == 1) {
            Node newnode; newnode.i = i, newnode.depth = 1;
            q.push(newnode);
        }
        children_removed[i] = adj[i].size();
    }

    while (q.size()) {
        Node curr = q.front(); q.pop();
        if (children_removed[curr.i] <= 1) {
            removals[curr.i] = (curr.depth);
            for (int next : adj[curr.i])
                if (children_removed[next] > 1) {
                    if (--children_removed[next] == 1) {
                        Node newnode; newnode.i = next; newnode.depth = curr.depth + 1;
                        q.push(newnode);
                    }
                }
        } 
    }

    int ans = 0;
    for (int i = 0; i < n; i++)
        if (removals[i] > k)
            ans++;
    
    cout << ans << nl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t; cin >> t;
    while (t--)
        solve();
}