#include <bits/stdc++.h>
#define int long long
#define nl " \n"
#define pi pair<int ,int>
#define ff first
#define ss second

using namespace std;
const int mxn = 2e5;
int a[mxn+1];

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int n; cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    a[n] = 0;
    
    

    int ans = 0;
    int ex = 0;
    int z = 0;
    
    set<int> b;
    vector<int> c;

    for (int i = 0; i <= n; i++)
        if (a[i]) b.insert(a[i]);
        else {
            if (b.size()) c.push_back((b.count(2)) ? 2 : 1);
            if (i != n) c.push_back(0);
            b.clear();
        }
    
    if (c.front()) c.front() = 2;
    if (c.back()) c.back() = 2;
    
    multiset<int> ck;
    if (c[0]) ck.insert(c[0]);
    
    for (int i = 1; i < c.size(); i++) {
        if (!c[i - 1] && !c[i]) {
            ans += ck.size() + !ck.count(2);
            ck.clear();
        } else if (c[i]) ck.insert(c[i]);
    }
    
    ans += ck.size() + !ck.count(2);

    cout << ans << nl;
}
