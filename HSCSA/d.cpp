#include <bits/stdc++.h>
#include <queue>
#define int long long
#define nl '\n'

using namespace std;

const int mxn = 1e5;
int a[mxn];

signed main() {
    cin.tie(0)->sync_with_stdio(false);
    
    priority_queue<pair<int, int>> even, odd;
    vector<pair<int, int>> list;
    map<int, bool> paired;

    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        char c;
        int l; cin >> c >> l;
        
        list.push_back({l, (c == 'S')});

        if (l % 2) odd.push({-l, (c == 'S')});
        else even.push({-l, (c == 'S')});
    }
   
    sort(list.begin(), list.end());

    int ans = 0;
    
    for (auto p : list) {
        
        int type = p.second;
        int length = p.first;

        if (paired[length])
            continue;

        if (length % 2) {
            if (even.top().second == type)
                ans++;
            paired[-even.top().first] = true;
            even.pop();
        } else {
            if (odd.top().second == type)
                ans++;
            paired[-even.top().first] = true;
            odd.pop();
        }
    }

    cout << ans << nl;
}
