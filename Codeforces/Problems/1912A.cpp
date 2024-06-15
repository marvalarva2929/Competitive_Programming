#include <bits/stdc++.h>
#define int long long
#define nl " \n"
#define pi pair<int, int>
#define ff first
#define ss second

using namespace std;

const int mxn = 1e5;
vector<int> a[mxn];
vector<pair<pi, int>> np[mxn];

signed main() {
    //cin.tie(0)->sync_with_stdio(false);

    int x, n; cin >> x >> n;
    
    for (int i = 0; i < n; i++) {
        int l; cin >> l;
        a[i].resize(l);

        for (int j = 0; j < l; j++)
            cin >> a[i][j];
        
        int s = 0, mn = INT_MAX;
        np[i].push_back({{mn, s}, i});
        
        for (int j = 0; j < l; j++) {
            s += a[i][j];
            mn = min(mn, s);

            if (s >= 0) {
                np[i].push_back({{mn, s}, i});
                mn = INT_MAX, s = 0;
            }
        }

        reverse(np[i].begin(), np[i].end());
    } 

    priority_queue<pair<pi, int>> pq;
    auto ins = [&pq](int i) -> void {
        pq.push({np[i].back().ff, i}); 
    };
    
    for (int i = 0; i < n; i++)
        ins(i);
    

    while (pq.size() && pq.top().ff.ff + x >= 0) {
        int s = pq.top().ff.ss, i = pq.top().ss;
            

        pq.pop();
        x += s;
                 
        np[i].pop_back(); 
        
        if (np[i].size())
            ins(i);

    }

    cout << x << nl;
}
