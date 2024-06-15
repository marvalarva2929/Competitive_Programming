#include <bits/stdc++.h>
#define int long long
#define pi pair<int, int>
#define ff first
#define ss second
#define nl " \n"

using namespace std;
const int mxn = 100;
int a[mxn];

void solve() {
    string a, b;
    cin >> a >> b;
    bool w = true;

    for (int i = 0; i < (int)a.size(); i++) {
        int s = a[i] - '0',
            t = b[i] - '0';
        
        if (s == t) continue;
        
        if (w) a[i] = '0' + max(s, t), b[i] = '0' + min(s, t);
        else a[i] = '0' + min(s, t), b[i] = '0' + max(s, t);
        w = 0; 
    }
    
    cout << a << nl << b << nl;
}

signed main() {
    int t; cin >> t;
    while (t--)
        solve();
}
