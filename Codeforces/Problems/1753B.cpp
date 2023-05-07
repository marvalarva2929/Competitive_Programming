using namespace std;
#include <bits/stdc++.h>
#define int long long
#define nl '\n'
#define MAX (int)5e5 + 10
int cnt[MAX];

void solve() {
    int n, x; cin >> n >> x;
    for (int i = 0; i < n; i++) {
        int e; cin >> e;
        cnt[e]++;
    }

    for (int i = 1; i < x; i++) 
        while (cnt[i] > i) 
            cnt[i] -= i + 1, cnt[i + 1]++;
    
    bool ans = 1;
    for (int i = 1; i < x; i++)
        ans &= (!cnt[i]);

    cout << (ans ? "Yes" : "No") << nl;

}

signed main() {
    cin.tie(0)->sync_with_stdio(false);
    
    int t = 1;
    while (t--)
        solve();
}