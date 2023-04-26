using namespace std;
#include <bits/stdc++.h>
#define int long long
#define nl '\n'
#define pi pair<int, int>

const int mxn = 3e2 + 10;
int a[mxn][mxn];
int r[mxn] = {0, 2, 1};
int n;

bool ok(int x) {
    for (int i = x; i < n; i++) {
        int mn = r[i], mx = r[i];
        for (int j = i + 1; j < n; j++) {
            mn = min(mn, r[j]);
            mx = max(mx, r[j]);
            if (mx - mn != a[i][j])
                return false;
        }
    }
    return true;
}

signed main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++)
            cin >> a[i][j];
    }

    r[n - 1] = 0;
    for (int i = n - 2; i >= 0; i--) {
        r[i] = r[i + 1] + a[i][i + 1];
        if (!ok(i))
            r[i] = r[i + 1] - a[i][i + 1];
    }
    for (int i = 0; i < n - 1; i++)
        cout << r[i] << " ";
    cout << r[n - 1] << nl;
}