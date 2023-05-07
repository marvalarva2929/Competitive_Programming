using namespace std;
#include <bits/stdc++.h>
#define int long long
#define nl '\n'
#define no "no"
#define yes "yes"
#define print(x, y, z) for (int i = y; i <= z; i++) {cout << x[i] << " ";} cout << nl;
#define pi pair<int, int> 

const int mxn = (int)2e5 + 10;

int a[mxn] = {};
int b[mxn] = {};
int pa[mxn] = {};
int pb[mxn] = {};
pi ar[mxn] = {};
pi br[mxn] = {};

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

int c2(int n) {
    return (n * (n - 1))/2;
}

void solve() {
    int n; cin >> n;

    for (int i = 0; i < n; i++)
        cin >> a[i],
        pa[a[i]] = i + 1;
    for (int i = 0; i < n; i++)
        cin >> b[i],
        pb[b[i]] = i + 1;

    int mn = pa[1], mx = pa[1];

    for (int i = 2; i <= n; i++) {
        if (pa[i] < mn || pa[i] > mx)
            ar[i].first = mn,
            ar[i].second = mx;
        mx = max(mx, pa[i]);
        mn = min(mn, pa[i]);
    }

    mn = pb[1], mx = pb[1];
    for (int i = 2; i <= n; i++) {
        if (pb[i] < mn || pb[i] > mx)
            br[i].first = mn,
            br[i].second = mx;
        mx = max(mx, pb[i]);
        mn = min(mn, pb[i]);
    }   

    int ans = 1; // the entire array has a MEX of n + 1, thus ans is >= 1

    for (int i = 2; i <= n; i++) {
        if (ar[i].first && br[i].first) {
            int l = min(ar[i].first, br[i].first);
            int r = max(ar[i].second, br[i].second);
            if ((pa[i] < l || pa[i] > r) && (pb[i] < l || pb[i] > r)) {
                int ll = 1,
                    rr = n;
                if (pa[i] < l)
                    ll = pa[i] + 1;
                else rr = pa[i] - 1;

                if (pb[i] < l)
                    ll = max(ll, pb[i] + 1);
                else rr = min(rr, pb[i] - 1);

                ans += (abs(rr - r) + 1) * (abs(ll - l) + 1);
            }
        }
    }

    {
        { // from 1 to min(pa[1], pb[1])
            int r = min(pa[1], pb[1]) - 1;
            ans += (r) + c2(r);  
            // cout << r << nl;
        } 
        { // from max(pa[1], pb[1]) to n
            int l = max(pa[1], pb[1]) + 1;
            int r = n - l + 1;
            // cout << r << nl;
            ans += r + c2(r);
        }
        { // from min(pa[1], pb[1]) to max(pa[1], pb[1])
            int l = min(pa[1], pb[1]) + 1;
            int r = max(pa[1], pb[1]) - 1;
            int m = r - l + 1;
            ans += m + c2(m);
        }
    }

    cout << ans << nl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t = 1;
    while (t--)
        solve();
}