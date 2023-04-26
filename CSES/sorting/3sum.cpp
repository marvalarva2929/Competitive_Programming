using namespace std;
#include <bits/stdc++.h>
#define int long long
#define nl '\n'

const int mxn = (int)5e3 + 10;
int a[mxn];
int t[mxn];

signed main() {
    cin.tie(0)->sync_with_stdio(false);
    int n, x; cin >> n >> x;
    iota(t, t + mxn, 0);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(t, t + n, [](const int & i, const int & j) -> bool {
        return a[i] < a[j];
    });
    sort(a, a + n);


    

    for (int i = 0; i < n; i++) {
        int sum = x - a[i];
        if (sum > 0) {
            int l = i + 1;
            int r = n - 1;
            while (l < r) {
                if (a[l] + a[r] == sum) {
                    cout << t[l] + 1 << " " << t[i] + 1 << " " << t[r] + 1 << nl;
                    return 0;
                } else if (a[l] + a[r] < sum) l++;
                else r--;
            }
        }
    }

    cout << "IMPOSSIBLE" << nl;
    return 0;
}

