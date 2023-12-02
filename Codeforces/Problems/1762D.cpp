#include <bits/stdc++.h>
#define int long long
#define nl endl
#define pi pair<int, int>
#define ff first
#define ss second

using namespace std;
vector<int> check;
map<pi, int> cache;

int query(int a, int b) {
    int x; 
    if (cache[{a, b}]) return cache[{a, b}];
    cout << "? " << a << " " << b << nl;
    cin >> x;
    return cache[{a, b}] = x;
}

void answer(int a, int b) {
    cout << "! " << a << " " << b << nl;
    int x; cin >> x;
}

void solve() {
    int n; cin >> n;
    if (n == 2) {
        answer(1, 2);
        return;
    }

    vector<int> a;
    cache.clear();

    int idx = 1;
    bool f = 1;
    while (idx < n && (f &= query(idx, idx + 1) == 1)) idx++;

    for (int i = idx; i <= n; i++)
        a.push_back(i);
    if (a.front() != 1) a.push_back(1);

    if (f) {
        answer(1, n);
        return;
    }
    
    while (a.size()) {
         
        if (a.size() == 2) {
            answer(a[0], a[1]);
            return;
        }
    
        int x = a.front();
        vector<int> a2, res(a.size());
       
        int mx = 0;
        for (int i = 1; i < a.size(); i++)
            res[i] = query(x, a[i]),
            mx = max(mx, res[i]);
    
        if (count(res.begin(), res.end(), mx) == 1) a2.push_back(x);
        for (int i = 1; i < res.size(); i++)
            if (res[i] == mx) a2.push_back(a[i]); 
         
        a = a2;
    }
}

signed main() {
    int t; cin >> t;
    while (t--)
        solve();
}
