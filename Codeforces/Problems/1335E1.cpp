#include <bits/stdc++.h>
using namespace std;
#define nl '\n'
#define f first
#define s second
#define int long long
#define MAX (int)2000 + 10
#define print(x, y, z) for (int i = y; i <= z; i++) {cout << x[i] << ' ';} cout << nl;
int a[MAX];

void solve() {
    memset(a, 0, sizeof(a));    
    int n; cin >> n;
    set<int> all;
    for (int i = 0; i < n; i++)
        cin >> a[i], all.insert(a[i]);

    int ans = 0;

    for (int x : all)
        for (int y : all) {
            vector<int> check;
            check.push_back(0);
            vector<int> cntx(n);
            vector<int> cnty(n);
            int mx = 1;
            for (int i = 0; i < n; i++)
                if (a[i] == x || a[i] == y) {
                    check.push_back(i);
                    if (a[i] == x)
                        cntx[i]++;
                    if (a[i] == y)
                        cnty[i]++;
                }

            if (check.size() == 2)
                goto skip;

            for (int i = 1; i < n; i++)
                cntx[i] += cntx[i - 1], cnty[i] += cnty[i - 1];
            
            for (int i = 0; i < n; i++) 
                for (int j = i; j < n; j++) 
                    if (cntx[n - 1] - cntx[j] == cntx[i])
                        mx = max(mx, (cntx[i] * 2) + (cnty[j] - cnty[i]));
                

            skip:
            ans = max(ans, mx);
            
        }

    cout << ans << nl;
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    int t; cin >> t;
    while (t--)
        solve();
}