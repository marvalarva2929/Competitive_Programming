#include <bits/stdc++.h>
#define int long long
#define nl " \n"

using namespace std;

void solve() {
    int n, k, x; cin >> n >> k >> x;
    
    vector<int> ans(n, 1);
    vector<int> a;
    int s = 0;
    
    for (int i = 0; i < n; i++) {
        s += ans[i];
        if (s != x) {
            a.push_back(s);
            s = 0; 
        }
    }
    
    if (a.size()) a.front() += s;
    else a.push_back(s); 


    for (int i : a) {
        if (i > k || i == x) {
            cout << "NO" << nl;
            return;
        }
    }
    
    cout << "YES" << nl;
    cout << a.size() << nl;     
    for (int i : a)
        cout << i << " ";
    cout << nl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t; cin >> t;
    while (t--)
        solve();
}
