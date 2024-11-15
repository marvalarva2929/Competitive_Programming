#include <bits/stdc++.h>
#define int long long
#define nl " \n"
#define pi pair<int, int>
#define ff first
#define ss second

using namespace std;
const int mxn = 2e5;
int a[mxn];
int n;

class SegmentMaxTree {
    public:

    SegmentMaxTree() {
        t = vector<int>(2 * n, 0);

        for (int i = n; i < n + n; i++)
            t[i] = a[i - n];

        build(); 
    }
    
    int query(int i, int j) {
        int ret = INT_MIN;
        for (i += n, j += n; i < j; i >>= 1, j >>= 1) {
            if (i&1) ret = max(ret, t[i++]);
            if (j&1) ret = max(ret, t[--j]);
        }
        return ret; 
    }

    private:
    
    vector<int> t;
    void build() {
        for (int i = n - 1; i > 0; i--)
            t[i] = max(t[i << 1], t[i << 1|1]);
    }


};

class SegmentMinTree {
    public:

    SegmentMinTree() {
        t.resize(2 * n);
        for (int i = n; i < n + n; i++)
            t[i] = a[i - n];
        build(); 
    }
    
    int query(int i, int j) {
        int ret = INT_MAX;
        for (i += n, j += n; i < j; i >>= 1, j >>= 1) {
            if (i&1) ret = min(ret, t[i++]);
            if (j&1) ret = min(ret, t[--j]);
        }
        return ret; 
    }

    private:
    
    vector<int> t;
    void build() {
        for (int i = n - 1; i > 0; i--)
            t[i] = min(t[i << 1], t[(i << 1)|1]);
    }


};
void solve() {
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    

    SegmentMaxTree segmax;
    SegmentMinTree segmin;

    map<int, vector<int>> occ;
    for (int i = n - 1; i >= 0; i--) {
        if (occ[a[i]].size() == 0)
            occ[a[i]].push_back(n);
        occ[a[i]].push_back(i);
    }
    
    for (int i = 0; i < n - 1; i++) {

        occ[a[i]].pop_back();
        int next = occ[a[i]].back();

        if (a[i + 1] > a[i]) {
            if (segmin.query(i + 1, next) < a[i]) {
                cout << "No" << nl;
                return;
            }  
        } else {
            if (segmax.query(i + 1, next) > a[i]) {
                cout << "NO" << nl;
                return;
            }
        }
    }
    
    cout << "YES" << nl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t; cin >> t;
    while (t--)
        solve();
}
