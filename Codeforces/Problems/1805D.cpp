#include <bits/stdc++.h>
#define int long long
#define nl '\n'

using namespace std;

const int mxn = 1e5;
vector<int> adj[mxn];
int maxLengthInSubtree[mxn];
int maxLength[mxn];
int offset[mxn];

int dfsToFindMaxInSubtree(int cur, int par) {
    int m = -1;
    for (int nex : adj[cur])
        if (nex != par)
            m = max(m, dfsToFindMaxInSubtree(nex, cur));
    maxLengthInSubtree[cur] = m + 1;
    return m + 1;
}

void dfsToFindMaxDistance(int cur, int par, int maxOutsideOfSubtree) {
    maxLength[cur] = max(maxLengthInSubtree[cur], maxOutsideOfSubtree);

    int maxChildren[2] = {-2, -2};
    for (int nex : adj[cur])
        if (nex != par) {
            if (maxLengthInSubtree[nex] > maxChildren[0]) {
                maxChildren[1] = maxChildren[0];
                maxChildren[0] = maxLengthInSubtree[nex];
            } else if (maxLengthInSubtree[nex] > maxChildren[1])
                maxChildren[1] = maxLengthInSubtree[nex];
        }

    for (int nex : adj[cur]) 
        if (nex != par) {
            int fromOtherBrances = (maxLengthInSubtree[nex] == maxChildren[0] ? maxChildren[1] : maxChildren[0]);
            int newDist = max(maxOutsideOfSubtree + 1, fromOtherBrances + 2);
            dfsToFindMaxDistance(nex, cur, newDist);
        }
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);
    
    int n; cin >> n;
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v; --u, --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfsToFindMaxInSubtree(0, -1);
    dfsToFindMaxDistance(0, -1, 0);
    
    for (int i = 0; i < n; i++)
        offset[maxLength[i]]++;

    for (int i = 1; i < n; i++)
        offset[i] += offset[i - 1];

    for (int i = 1; i <= n; i++)
        cout << offset[i - 1] + (offset[n - 1] - offset[i - 1] > 0) << " ";
    cout << nl;
}
