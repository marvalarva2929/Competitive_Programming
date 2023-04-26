using namespace std;
#include <bits/stdc++.h>
#define int long long
#define nl '\n'
#define no "no"
#define yes "yes"
#define print(x, y, z) for (int i = y; i <= z; i++) {cout << x[i] << " ";} cout << nl;
#define ff first
#define ss second
#define pi pair<int, int>

const int mxn = 500000;
pi ab[mxn];
int mx[mxn];
int n;

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
    cin >> n;
    fill(mx, mx + n, LLONG_MIN);
    mx[n] = INT_MIN;
    int ans = LLONG_MAX;
    for (int i = 0; i < n; i++)
        cin >> ab[i].ff >> ab[i].ss;

    sort(ab, ab + n);
    mx[n - 1] = ab[n - 1].ss;
    for (int i = n - 2; i >= 0; i--)
        mx[i] = max(mx[i + 1], ab[i].ss);

    set<int> before;

    for (int i = 0; i < n; i++) { // the minimum difference if a[i] is the maximum gift given to person 1
        int mn = mx[i + 1];
        ans = min(ans, abs(mn - ab[i].ff));
        if (mn < ab[i].ff && before.size()) {
            auto bel = before.lower_bound(ab[i].ff);
            auto abo = bel;
            if (bel != before.begin())
                --bel;

            
            if (*bel >= mn)
                ans = min(ans, abs(*bel - ab[i].ff));

            if (abo != before.end()) 
                if (*abo >= mn)
                    ans = min(ans, abs(*abo - ab[i].ff));
        }
        before.insert(ab[i].ss);
    }
    cout << ans << nl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t; cin >> t;
    while (t--)
        solve();
}