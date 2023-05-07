using namespace std;
#include <bits/stdc++.h>
#define int long long
#define nl '\n'
#define no "no"
#define yes "yes"
#define print(x, y, z) for (int i = y; i <= z; i++) {cout << x[i] << " ";} cout << nl;
#define pi pair<int, int>
#define ff first
#define ss second

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

const int mxn = 2e5;
pi a[mxn];
int n;
string sss;

void solve(int t) {
    cin >> n >> sss;

    int last = -1;
    int m = 0;
    vector<int> odds;

    for (char c : sss) {
        int x = c - '0';
        if (x == last)
            a[m - 1].ss++;
        else a[m++] = {x, 1};
        last = x;
    }    


    for (int s = 0; s < m; s++)
        if (a[s].ss % 2)
            odds.push_back(s);

    int ans = 0;
    
    for (int i = 0; i < (int)odds.size() - 1; i += 2) {
        ans += odds[i + 1] - odds[i];
    }

    cout << ans << nl;

}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t; cin >> t;
    for (int i = 1; i <= t; i++)
        solve(i);
}