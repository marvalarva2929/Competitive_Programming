#include <bits/stdc++.h>
#define int long long
#define nl '\n'

using namespace std;

const int mxn = 2000;

void solve() {
    int n, k, x; cin >> n >> k >> x;
    --x;

    string s; cin >> s;
    string res = "";
    reverse(s.begin(), s.end());
    
    for (int i = 0; i < n; i++)
        if (s[i] == 'a')
            res += 'a';
        else {
            int j = i;
            while (j + 1 < n && s[j + 1] == s[j])
                j++;
            string bees = "";
            int cnt = (((j - i + 1) * k) + 1);
            for (int k = 0; k < x % cnt; k++)
                bees += 'b';
            res += bees;
            x /= cnt;
            i = j;
        }
    
    reverse(res.begin(), res.end());
    cout << res << nl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t; cin >> t;
    while (t--)
        solve();
}
