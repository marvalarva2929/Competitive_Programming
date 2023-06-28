#include <bits/stdc++.h>
#define int long long
#define nl " \n"

using namespace std;

const int mxn = 3e5;
int a[mxn], closed[mxn];

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int n, k; cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int cnt = 0, sum = 0, ans = 0;

    for (int i = n - 1; i >= 0; --i) {
        sum -= cnt;
        a[i] -= sum;
        cnt -= closed[i];
        
        if (a[i] <= 0) continue;

        int len = min(i + 1, k);
        int need = (a[i] + len - 1) / len;

        ans += need;
        sum += need * len;
        cnt += need;
        
        if (i - len >= 0) closed[i - len] += need;
    }
    
    cout << ans << nl;
}
