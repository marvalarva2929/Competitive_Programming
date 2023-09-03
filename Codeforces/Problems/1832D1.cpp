#include <bits/stdc++.h>
#define int long long
#define nl " \n"
#define pi pair<int, int>
#define ff first
#define ss second

using namespace std;
const int mxn = 1e3;
int a[mxn];

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int n, q; cin >> n >> q;    
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n);

    for (int i = 0; i < q; i++) {
        int x; cin >> x;

        if (x <= n) {
            int t = x;
            int ans = INT_MAX;
            for (int j = 0; j < n; j++)
                ans = min(ans, a[j] + max((int)0, t--)); 
            cout << ans << nl[i == q -1]; 
        } else {
            int ans = INT_MAX;
            if (x % 2 == n % 2) {
                int t = x; 
                vector<int> b(a, a + n); 
                int mn = INT_MAX, s = 0;

                for (int j = 0; j < n; j++)
                    b[j] += max((int)0, t--),
                    mn = min(mn, b[j]);
                t = max((int)0, t);

                for (int j = 0; j < n; j++)
                    s += b[j] - mn;

                int left = t/2;
                
                left -= s;
                if (left > 0) mn -= (left + n - 1) / n;
                ans = mn;
            } else {
                int t = x; 
                vector<int> b(a, a + n);
                int mn = INT_MAX, s = 0; 

                for (int j = 0; j < n - 1; j++)
                    b[j] += max((int)0, t--),
                    mn = min(mn, b[j]);
                mn = min(mn, b[n - 1]);
                t = max(t, (int)0);
                
                for (int j = 0; j < n; j++)
                    s += b[j] - mn;
                
                int left = t/2;
                //cout << left << " " << t << " " << s << nl; 
                left -= s;
                if (left > 0) mn -= (left + n - 1) / n;
                ans = mn;
            }
            cout << ans << nl[i == q -1];
        } 
    }
}
