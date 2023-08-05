#include <bits/stdc++.h>
#define int long long
#define nl endl
#define pi pair<int, int>
#define ff first
#define ss second

using namespace std;
map<array<int, 3>, int> cache;

int ask(int i, int j, int k) {
    vector<int> ch = {i, j, k};
    sort(ch.begin(), ch.end());
    i = ch[0], j = ch[1], k = ch[2];
    
    if (cache[{i, j, k}]) return cache[{i, j, k}] - 1;
    
    cout << "? " << i + 1 << " " << j +1 << " " << k + 1<< nl;
    int x; cin >> x;
    cache[{i, j, k}] = x + 1; 
    return x;
}

void solve() {
    int n; cin >> n;

    map<int, vector<int>> cnt;
    int mx = 0;
    cache.clear();

    for (int i = 1; i < n - 1; i++) {
        int x = ask(0, i, n - 1);
        cnt[x].push_back(i);
        mx = max(mx, x); 
    }
    

    if (cnt.size() == 1 && min(ask(0, 1, 2), ask(n - 3, n - 2, n - 1)) < mx) {
        cout << "! " << 1 << " " << n << nl; 
    } else {
        int f = cnt[mx].front(); 
        cnt.clear();
        pi ans = {0, 0};

        for (int i = 1; i < n; i++)
            if (i != f) {
                int x = ask(0, i, f);
                cnt[x].push_back(i);        
                mx = max(mx, x); 
            }
    
        if (cnt.size() == 1) cout << "! " << 1 << " " << f + 1 << endl;
        else {
            cout << "! " << f + 1 << " " << cnt[mx].front() + 1 << endl;
        }
    }
}

signed main() {
    int t; cin >> t;
    while (t--)
        solve();
}
