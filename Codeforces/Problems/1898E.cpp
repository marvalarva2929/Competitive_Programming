#include <bits/stdc++.h>
#define int long long
#define pi pair<int, int>
#define ff first
#define ss second
#define nl " \n"

using namespace std;
const int mxn = 2e5;
int a[mxn], b[mxn];

bool solve() {
    int n, m; cin >> n >> m;   
    string s, t; cin >> s >> t;

    for (int i = 0; i < n; i++)
        a[i] = (s[i] - 'a');
    for (int i = 0; i < m; i++)
        b[i] = (t[i] - 'a');
    
    vector<queue<int>> pos(26, queue<int>());
    
    set<int> a; a.insert(5);
    a.erase(a.end());
    auto it = a.begin();
    it = a.erase(it);

    cout << (it == a.end()) << nl;
    
    return 0;
    //for (int i = 0; i < n; i++)
     //   pos[a[i]].push(i);
    
    //for (int i = 0; i < m; i++) {
    //    if (pos[b[i]].empty()) return 0;
    //    for (int j = 0; j < b[i]; j++)
    //        while (pos[j].size() && pos[j].front() < pos[b[i]].front()) pos[j].pop();
    //    pos[b[i]].pop(); 
    //}
    //return 1;
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t; cin >> t;
    while (t--)
        cout << (solve() ? "YES" : "NO") << nl;
}
