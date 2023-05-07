using namespace std;
#include <bits/stdc++.h>
#define int long long
#define nl '\n'
#define min(x, y) min((int)x, (int)y)
int choose2(int n) {
    return (n * (n - 1))/2;
}

void solve() {
    int n, k; cin >> n >> k;
    string a, b; cin >> a >> b;
    vector<char> ac;
    set<char> bc;
    for (char c : a)
        bc.insert(c);

    for (char c : bc)
        ac.push_back(c);

    int m = min(bc.size(), k);
    vector<int> subsets;

    int ans = 0;
    // cout << m << nl;
    for (int i = 0; i < (1 << (int)bc.size()); i++)
        if (__builtin_popcount(i) == m)
            subsets.push_back(i);

    for (int subset : subsets) {
        // cout << subset << nl;
        set<char> curr;
        for (int i = 0; i < bc.size(); i++)
            if ((subset >> i) & 1)
                curr.insert(ac[i]);

        // for (char b : curr)
        //     cout << b << " ";
        // cout << nl;

        int i = 0;
        int c_ans = 0;

        while (i < n) {
            int j = i;
            while (j < n && (a[j] == b[j] || curr.count(a[j]))) j++;   
            c_ans += choose2(j - i + 1);
            // cout << i << " " << j << nl;
            i = j + 1;
        }

        ans = max(ans, c_ans);
    }
    cout << ans << nl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t; cin >> t;
    while (t--)
        solve();
}