#include <bits/stdc++.h>
#define int long long
#define nl '\n'
#define pi pair<int, int>
#define ff first
#define ss second

using namespace std;

void solve() {
    int n; cin >> n;
    set<int> wout;
    set<pi> with;
    unordered_map<int, int> ans;

    for (int i = 1; i <= n; i++)
        wout.insert(-i);

    for (int i = 0; i < n/2; i++) {
        int x; cin >> x;
        wout.erase(-x);
        with.insert({-x, i}); 
    }

    auto i = with.begin();
    priority_queue<int> pq;

    for (int x : wout) {

        while (i != with.end() && -i->ff > -x) {
            pq.push(i->ss);
            ++i;
            if (i == with.end()) break;
        }   
        
        if (!pq.size()) {
            cout << -1 << nl;
            return;
        }
        
        ans[pq.top()] = -x;
        pq.pop(); 
    }
    
    vector<int> ret(n);
    for (auto& x : with)
        ret[x.ss * 2 + 1] = -x.ff,
        ret[x.ss * 2] = ans[x.ss];
    
    for (int i : ret)
        cout << i << " \n"[i == ret.back()];
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t; cin >> t;
    while (t--)
        solve();
}
