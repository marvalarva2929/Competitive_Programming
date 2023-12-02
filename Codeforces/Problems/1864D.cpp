#include <bits/stdc++.h>
#define int long long
#define nl " \n"
#define pi pair<int, int>
#define ff first
#define ss second

using namespace std;
const int mxn = 3e3;
int a[mxn][mxn];

void solve() {
    int n; cin >> n;
    vector<int> lp(n + n), rp(n + n);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            char c; cin >> c;
            a[i][j] = (c & 1);
        }
    
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int cnt = 0;
        vector<int> nlp = lp, nrp = rp;

        for (int j = 0; j < n; j++) {
            int x = a[i][j],
                lt = i + n - 1 - j,
                rt = i + j;

            x ^= (rp[rt] - lp[lt + 1]) % 2;
            cnt += x, ans += x;
        
            nlp[lt] += cnt, nrp[rt] += cnt;
        }
            
        for (int j = i + n; j < n + n; j++)
            nrp[j] += cnt;

        lp = nlp;
        rp = nrp;
    }
    
    cout << ans << nl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t; cin >> t;
    while (t--)
        solve();
}
