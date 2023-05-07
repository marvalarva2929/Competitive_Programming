using namespace std;
#include <bits/stdc++.h>    
#define int long long
#define nl '\n'
vector<int> inRow[300];

void solve() {
    int n, m; cin >> n >> m;
    for (int i = 0; i < n; i++)
        inRow[i].clear();
    int a[n * m];
    int t[n * m];
    iota(t, t + (n * m), 0);
    priority_queue<int, vector<int>, greater<int>> p[n * m + 1];
    unordered_map<int, int> tag;

    for (int i = 0; i < n * m; i++)
        cin >> a[i];

    auto cmp = [&a](int & i, int & j) -> bool { 
        return a[i] < a[j];
    };

    sort(t, t + (n * m), cmp);
    int tags = 0;

    for (int i = 0; i < n; i++) 
        for (int j = 0; j < m; j++) {
            int ind = (i * m) + j;
            if (!tag[a[t[ind]]])
                tag[a[t[ind]]] = ++tags;
            p[tag[a[t[ind]]]].push(i);
        }   

    int ans = 0;
    for (int i = 0; i < n * m; i++) {  
        int row = p[tag[a[i]]].top();
        p[tag[a[i]]].pop();
        for (int person : inRow[row])
            if (person < a[i])
                ans++;
        inRow[row].push_back(a[i]);
    }
    cout << ans << nl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t; cin >> t;
    while (t--)
        solve();
}