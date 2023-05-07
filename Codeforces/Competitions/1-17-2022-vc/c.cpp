using namespace std;
#include <bits/stdc++.h>
#define int long long
#define nl '\n'
#define MAX (int)1e5 + 10

int ci(char a) { return (int)(a - 'a'); }

void solve() {
    int n; string s; cin >> n >> s;
    vector<int> p(26);
    int t[26] = {};
    char q[n] = {};
    int len = 0;

    iota(t, t + 26, 0);
    for (char c : s)
        p[ci(c)]++;


    auto cmp = [&p](int & a, int & b) -> bool { 
        return p[a] > p[b]; 
    };

    sort(t, t + 26, cmp);

    // for (int i : t)
    //     cout << i << " ";
    // cout << nl;

    int f = 0, ans = 0;
    for (int i = 1; i <= 26; i++) {
        if (n % i) continue;
        int s = 0;
        for (int j = 0; j < i; j++)
            s += min(p[t[j]], n/i);

        // cout << i << " " << s << nl;
        
        if (s > ans) ans = s, f = i;
    }

    for (int i = 0; i < f; i++) {
        if (p[t[i]] > n/f) p[t[i]] = n/f;
        else if (p[t[i]] < n/f)
            for (int j = p[t[i]]; j < n/f; j++)
                q[++len] = t[i] + 'a';
    }

    for (int i = f; i < 26; i++)
        p[t[i]] = 0;

    for (int i = 0; i < n; i++)
        if (p[ci(s[i])]) p[ci(s[i])]--;
        else s[i] = q[len--];

    cout << n - ans << nl << s << nl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t; cin >> t;
    while (t--)
        solve();
}