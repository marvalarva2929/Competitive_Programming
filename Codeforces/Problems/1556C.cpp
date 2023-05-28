#include <bits/stdc++.h>
#define int long long
#define nl '\n'

using namespace std;

const int mxn = 1000;
int a[mxn];

signed main() {
    cin.tie(0)->sync_with_stdio(false);
    
    int n, ans = 0; cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    for (int i = 0; i < n; i += 2) {
        int sum = 0, mn = 0;
        int left = a[i];
        for (int j = i + 1; j < n; j++)
            if (j % 2) {
                int right = a[j];
                    
                int l = -mn, r = sum - mn;

                if (a[i] < -mn) break;
                
                left = left - l + (j - i > 1);
                right = right - r + (j - i > 1);

                ans += max((int)0, min(left, right));
                sum -= a[j];
                mn = min(mn, sum);
                left = a[i];
            } else sum += a[j]; 
    }

    cout << ans << nl;
}

