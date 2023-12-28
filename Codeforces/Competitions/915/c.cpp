#include <bits/stdc++.h>
#define int long long
#define nl " \n"
#define pi pair<int, int>
#define ff first
#define ss second

using namespace std;

void solve() {
    int n; cin >> n;
    string s; cin >> s;
     
    char mx = '0';
    vector<int> lex;
    for (int i = n -1; i >= 0; i--)
        if (s[i] >= mx) mx = s[i], lex.push_back(i); 
    
    int ans = 0;
    for (int i = 0; i < lex.size(); i++)
        if (s[lex[i]] == mx) { ans = i; break; };
    
    reverse(lex.begin(), lex.end());
    
    for (int i = 0; i < (lex.size()) / 2; i++) {
        swap(s[lex[i]], s[lex[lex.size() - i - 1]]);  
    }
    
    if (is_sorted(s.begin(), s.end()))
        cout << ans << nl;
    else cout << -1 << nl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t; cin >> t;
    while (t--)
        solve();
}
