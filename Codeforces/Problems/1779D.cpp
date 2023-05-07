using namespace std;
#include <bits/stdc++.h>
#define int long long
#define nl '\n'

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};


void solve() {
    int n; cin >> n;
    int a[n] = {}, b[n] = {};
    unordered_map<int, int, custom_hash> razWith;
    bool flag = false;

    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        if (a[i] < b[i])
            flag = true;
    }

    int q; cin >> q;
    for (int i = 0; i < q; i++)
        { int x; cin >> x; razWith[x]++; }

    if (flag) {
        cout << "NO" << nl;
        return;
    }

    stack<int> inUse;

    for (int i = 0; i < n; i++) {
        while (inUse.size() && b[i] > inUse.top())
            inUse.pop();

        if ((!inUse.size() || inUse.top() != b[i]) && a[i] != b[i]) {
            if (razWith[b[i]] > 0) {
                inUse.push(b[i]);
                razWith[b[i]]--;
            } else {
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