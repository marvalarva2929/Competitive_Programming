#include <bits/stdc++.h>
#define int long long
#define nl " \n"
#define pi pair<int, int>
#define ff first
#define ss second

using namespace std;

const int mxm = 1e5;
vector<vector<int>> back[mxm + 1];
int n, m, k;

int dfs(int x) {
    if (x <= 1) return 0;
    int ret = 0;

    for (auto seg : back[x])
        ret += dfs(seg.front() - 1) + 1;
    
    return ret;
}

signed main() {
    cin >> n >> m >> k;
    
    vector<vector<int>> segs;
    int ans = 0;

    for (int i = 0; i < k; i++) {
        int l; cin >> l;
        vector<int> seg;
        int last = -1;
        for (int j = 0; j < l; j++) {
            int x; cin >> x;
            if (last == -1 || x == last + 1) { last = x; seg.push_back(x); }
            else {
                back[last].push_back(seg);
                seg.clear();
                seg.push_back(x);
                ans++; 
            } 
            last = x; 
        }
        back[last].push_back(seg); 
    }
    
    cout << dfs(n) << nl; 
}
