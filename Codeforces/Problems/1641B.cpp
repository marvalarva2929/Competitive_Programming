#include <bits/stdc++.h>
#define int long long
#define nl " \n"
#define pi pair<int, int>
#define ff first
#define ss second

using namespace std;
const int mxn = 500;
int a[mxn];
vector<pi> ops;
vector<int> ans;
int mdf = 0;

void rev(int k) {
    for (int i = 0; i < k; i++) {
        ops.emplace_back(a[i], i + k + mdf); 
    } 
    mdf += (2 * k);
    if (k) ans.push_back(2 * k);
}

void solve() {
    map<int, int> occ;
    int n; cin >> n;
    vector<int> b(n);
    set<int> all;
    ops.clear();
    ans.clear();
    mdf = 0;

    for (int i = 0; i < n; i++)
        cin >> a[i], b[i] = a[i], occ[a[i]]++, all.insert(a[i]);

    for (int i = 0; i < n; i++) 
        if (occ[a[i]] % 2) {
            cout << -1 << nl;
            return;
        }
    
    sort(b.begin(), b.end());
    
    int cur = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (a[i] != b[i]) {
            int idx = 0;
            for (int j = 0; j < i; j++)
                if (a[j] == b[i]) idx = j; 
            
            rev(idx + 1);
            reverse(a, a + idx + 1);
            rev(i + 1);
            reverse(a, a + i + 1);
             
        }
    }
    
    //for (int i = 0; i < n; i++)
    //    cout << a[i] << nl[i == n -1]; 

    cout << ops.size() << nl;
    for (pi& oper : ops) 
        cout << oper.ss << " " << oper.ff << nl;
    cout << all.size() + ans.size() << nl;
    
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
    for (int x : all)
        cout << occ[x] << " ";
    cout << nl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t; cin >> t;
    while (t--)
        solve();
}
    
