#include <bits/stdc++.h>
#define int long long
#define pi pair<int, int>
#define ff first
#define ss second
#define nl " \n"

using namespace std;
const int mxn = 1e3;

class mnSegmentTree {
    public:
 
    vector<int> a;
    int n;
   
    void build() {
        for (int i = n - 1; i; i--)
            a[i] = min(a[i<<1], a[i<<1|1]);
    }
    
    int rng(int l, int r) {
        int ans = a[l + n];
        for (l += n, r += n; l < r; l>>=1, r>>=1) {
            if (l&1) ans = min(ans, a[l++]);
            if (r&1) ans = min(ans, a[--r]);
        }
        return ans;
    }

    mnSegmentTree(vector<int> ta) {
        a.resize(ta.size() * 2);
        n = ta.size();

        for (int i = ta.size(); i < a.size(); i++)
            a[i] = ta[i - ta.size()];

        build();
    }
};

class mxSegmentTree {
    public:
 
    vector<int> a;
    int n;
   
    void build() {
        for (int i = n - 1; i; i--)
            a[i] = max(a[i<<1], a[i<<1|1]);
    }
    
    int rng(int l, int r) {
        int ans = a[l + n];
        for (l += n, r += n; l < r; l>>=1, r>>=1) {
            if (l&1) ans = max(ans, a[l++]);
            if (r&1) ans = max(ans, a[--r]);
        }
        return ans;
    }

    mxSegmentTree(vector<int> ta) {
        a.resize(ta.size() * 2);
        n = ta.size();

        for (int i = ta.size(); i < a.size(); i++)
            a[i] = ta[i - ta.size()];

        build();
    }
};

bool solve() {
    int n; cin >> n;
    vector<int> a(n), b(n);

    for (int i = 0; i < n; i++)
         cin >> a[i], a[i]--;
    for (int i = 0; i < n; i++)
        cin >> b[i], b[i]--;
    
    for (int i = 0; i < n; i++)
        if (a[i] > b[i]) return 0;

    vector<int> can(n, 0);
    
    {

        mxSegmentTree mxa = mxSegmentTree(a);
        mnSegmentTree mnb = mnSegmentTree(b);
        
        vector<int> lst(n, -1);

        for (int i = 0; i < n; i++) {
            lst[a[i]] = i;
            int ls = lst[b[i]];
            if (ls == i) can[i] = 1; 
            else if (ls != -1) {
                int top = mnb.rng(ls + 1, i);
                int bot = mxa.rng(ls + 1, i);
                can[i] |= (top >= b[i] && bot <= b[i]); 
            }
        }
    }

    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    {
        mxSegmentTree mxa = mxSegmentTree(a);
        mnSegmentTree mnb = mnSegmentTree(b);
        
        vector<int> lst(n, -1);

        for (int i = 0; i < n; i++) {
            lst[a[i]] = i;
            int ls = lst[b[i]];
            if (ls == i) can[n - i - 1] = 1;
            else if (ls != -1) {
                int top = mnb.rng(ls + 1, i);
                int bot = mxa.rng(ls + 1, i);
                can[n - i - 1] |= (top >= b[i] && bot <= b[i]); 
            }
        }
    }
    
    int ans = 1;
    for (int i = 0; i < n; i++)
        ans &= can[i];

    return ans;
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t; cin >> t;
    for (int i = 1; i <=t; i++) {    
        //if (i == 776) {
        //    int n; cin >> n;
        //    vector<int> a(n), b(n);
        //    string s; s.push_back((char)(n + '0'));
        //    
        //    for (int i = 0; i < n; i++)
        //        cin >> a[i], s.push_back((char)(a[i] + '0')); 
        //    for (int i = 0; i < n; i++)
        //        cin >> b[i], s.push_back((char)(b[i] + '0')); 
        //
        //    cout << s << nl; 
        //} else
        cout << (solve() ? "YES" : "NO") << nl;
    }
}
