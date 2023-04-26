using namespace std;
#include <bits/stdc++.h>
#define int long long
#define nl '\n'

void solve() {
    string s; cin >> s;
    int n = s.size();
    reverse(s.begin(), s.end());
    int a[n] = {};
    set<int> carry; // keeps a list of digits that can be used to carry
    vector<int> canCarry;

    for (int i = 0; i < n; i++)
        a[i] = s[i] - '0';

    for (int i = 0; i < n; i++)
        if (a[i])
            for (int j = i - 2; j >= 0; j -= 2)
                carry.insert(j);

    for (int i : carry)
        canCarry.push_back(i);
    int m = canCarry.size();
    int ans = 0;

    for (int i = 0; i < (1 << m); i++) { // goes through every possible way to carry digits
        int c_ans = 1;
        vector<int> b(a, a + n);
        for (int j = 0; j < m; j++)
            if ((i >> j) & 1)
                b[canCarry[j] + 2]--, b[canCarry[j]] = 10 - b[canCarry[j]] - 2;
        
        for (int i : b)
            c_ans *= (i + 1); // There's i + 1 ways to add to a digit
        ans += c_ans;
    }
    cout << ans - 2 << nl; // don't count 0 + n or n + 0
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t; cin >> t;
    while (t--)
        solve();
}