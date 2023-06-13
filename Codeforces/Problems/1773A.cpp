#include <bits/stdc++.h>
#define int long long
#define nl '\n'

using namespace std;
const int mxn = 1e5;
int a[mxn], l[mxn+1];
int q[mxn];

void solve() {
    int n; cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i],
        l[a[i]] = i + 1;

    iota(q, q + n, 1);

    for (int i = 0; i < 100; i++) {
        random_shuffle(q, q + n);
        vector<int> p(n);
        bool stop = false;
        for (int j = 0; j < n; j++)
            if (q[j] == j + 1) {stop = true; break; }
            else p[q[j]-1] = l[j + 1];          
    

        for (int j = 0; j < n; j++)
            if (p[j] == j + 1) {
                stop = true;
                break;
            }
        
        if (stop) continue;

        cout << "Possible" << nl;
        for (int j = 0; j < n; j++)
            cout << p[j] << " \n"[j == n - 1];
        for (int j = 0; j < n; j++)
            cout << q[j] << " \n"[j == n - 1];
        return; 
    }
    
    cout << "Impossible" << nl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);
    
    int t; cin >> t;
    while (t--)
        solve();
}
