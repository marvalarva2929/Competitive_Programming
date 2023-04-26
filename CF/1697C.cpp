using namespace std;
#include <bits/stdc++.h>
#define int long long
#define nl '\n'

void solve() {
    int n; string s, t; cin >> n >> s >> t;

    int j = 0;

    for (int i = 0; i < 3; i++)
        if (count(s.begin(), s.end(), 'a' + i) != count(t.begin(), t.end(), 'a' + i)) 
            { cout << "NO" << nl; return; }

    for (int i = 0; i < n; i++) {
        if (s[i] == 'b') continue;
        while (j < n && t[j] == 'b') j++;

        if (s[i] != t[j] || s[i] == 'a' && i > j || s[i] == 'c' && i < j) 
            { cout << "NO" << nl; return; }
        j++;
    }
   

    cout << ("YES") << nl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t; cin >> t;
    while (t--)
        solve();
}