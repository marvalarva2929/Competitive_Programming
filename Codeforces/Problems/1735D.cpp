using namespace std;
#include <bits/stdc++.h>
#define int long long
#define nl '\n'
#define no "no"
#define yes "yes"
#define print(x, y, z) for (int i = y; i <= z; i++) {cout << x[i] << " ";} cout << nl;

const int mxn = (int)1e3 + 10;

vector<int> inv(vector<int> a, vector<int> b) {
    vector<int> ret(a.size(), 0);
    for (int i = 0; i < a.size(); i++) {
        ret[i] = (6 - (a[i] + b[i])) % 3;
    }
    return ret;
}

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
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
    int n, k; cin >> n >> k;
    vector<vector<int>> card(n, vector<int>(k, 0));
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < k; j++)
            cin >> card[i][j];
    
    map<vector<int>, int> cnt;

    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++) {
            cnt[inv(card[i], card[j])]++;
            // cout << i << " : ";
            //  print(card[i], 0, k - 1);
            // cout << j << " : ";
            //  print(card[j], 0, k - 1);
            // cout << "inv: "; print(inv(card[i], card[j]), 0, k - 1);
        }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        int c = cnt[card[i]];
        ans += (c * (c - 1)) / 2;
    }
    cout << ans << nl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t = 1;
    while (t--)
        solve();
}