using namespace std;
#include <bits/stdc++.h>
#define int long long
#define nl '\n'
#define no "no"
#define yes "yes"
#define print(x, y, z) for (int i = y; i <= z; i++) {cout << x[i] << " ";} cout << nl;

const int mxn = (int)1e5 + 10;
int a[mxn];
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

int neg_cost(int i, int j) {
    return ((n - (i + 1)) * (i + 1));
}

// int pos_cost(int i, int j) {
//     if (a[i] == a[j])
//         return 0;
//     return ((n - (i + 1)) * (i + 1));
// }

void solve() {
    int q; cin >> n >> q;
    fill(a, a + n, 0);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int init = 0;
    for (int i = 1; i <= n; i++) // the maximum beauty if all elements are unique
        init += (i) * (n - i + 1);

    for (int i = 0; i < n - 1; i++) // removing some beauty if adjacent elements are the same
        if (a[i] == a[i + 1])
            init -= neg_cost(i, i + 1);    

    for (int i = 0; i < q; i++) {
        int j, p; cin >> j >> p;
        j--;

        if (j > 0 && a[j] == a[j - 1]) {
            if (a[j - 1] != p)
                init += neg_cost(j - 1, j);
        } else if (j > 0 && a[j] != a[j - 1]) {
            if (a[j - 1] == p)
                init -= neg_cost(j - 1, j);
        }

        if (j < (n - 1) && a[j] == a[j + 1]) {
            if (a[j + 1] != p)
                init += neg_cost(j, j + 1);
        } else if (j < (n - 1) && a[j] != a[j + 1]) {
            if (a[j + 1] == p)
                init -= neg_cost(j, j + 1);
        }

        a[j] = p;

        cout << init << nl;
    }
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t = 1;
    while (t--)
        solve();
}