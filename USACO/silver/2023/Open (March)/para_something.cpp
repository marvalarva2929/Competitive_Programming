using namespace std;
#include <bits/stdc++.h>
#define int long long
#define nl '\n'

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    string t; cin >> t;
    int n = t.size();   
    string b = "bessie";
    int cnt[7] = {};
    int ans = 0;

    for (int i = 0; i < n; i++) {
        cnt[0]++;
        for (int j = 5; j >= 0; j--)
            if (t[i] == b[j])
                cnt[j + 1] += cnt[j],
                cnt[j] = 0;
        
        ans += (n - i) * cnt[6];
        cnt[0] += cnt[6];
        cnt[6] = 0;
    }

    cout << ans << nl;
}