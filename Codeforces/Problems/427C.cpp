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
#define MOD (int)1e9 + 7
int cost[MAX];
bool visited[MAX];
int var[MAX];
int minp[MAX];
vector<int> adj[MAX];
vector<int> rev[MAX];
int comp[MAX];
vector<int> finishingTimes;
int numOfComponents = 0;
int numOfWays = 1, minCost = 0;
int n;

void dfs(int x, int cmp) {
    if (visited[x]) return;
    visited[x] = true;
    comp[x] = cmp;

    for (auto out : rev[x]) 
        if (!visited[out]) 
            dfs(out, cmp);

}

void revdfs(int x) {
    if (visited[x]) return;
    visited[x] = true;

    for (auto out : adj[x])
        if (!visited[out]) 
            revdfs(out);   

    finishingTimes.push_back(x);
}

void findSCC() {

    for (int i = 1; i <= n; i++)
        if (!visited[i]) 
            revdfs(i);


    reverse(finishingTimes.begin(), finishingTimes.end());
    memset(visited, false, sizeof(visited));


    for (int fin : finishingTimes) { 
        if (!visited[fin]) 
            numOfComponents++;
            dfs(fin, numOfComponents);
    }
}

int32_t main() {
    cin >> n;
    int maxc = INT_MIN;
    for (int i = 1; i <= n; i++) {
        cin >> cost[i];
        maxc = max(maxc, cost[i]);
    }
    // cout << " --- " << maxc << nl;
    int m; cin >> m;
    for (int i = 0; i < m; i++) {
        int to, from; cin >> to >> from;
        adj[to].push_back(from);
        rev[from].push_back(to);
    }
    findSCC();

    // for (int i = 1; i <= n; i++)
    //     cout << i << " : " << comp[i] << nl;

    int k = numOfComponents;

    for (int i = 1; i <= k; ++i)
        minp[i] = maxc + 1;
    
    for (int i = 1; i <= n; ++i)
        minp[comp[i]] = min(minp[comp[i]], cost[i]);
    
    for (int i = 1; i <= k; ++i)
        minCost += minp[i];
    
    for (int i = 1; i <= n; ++i)
        if (cost[i] == minp[comp[i]])
            ++var[comp[i]];
    
    int vars = 1;
    for (int i = 1; i <= k; ++i) {
        vars *= var[i];
    }
    
    cout << minCost << " " << vars % 1000000007  << nl;
}   