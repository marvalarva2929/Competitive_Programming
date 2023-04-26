using namespace std;
#include <bits/stdc++.h>
#define int long long
#define nl '\n'

int edges = 0;

int ci(char a) {
    if ('a' <= a && a <= 'z')
        return a - 'a';
    else return a - 'A' + 26;
}

void solve() {
    string s, t; cin >> s >> t;
    int n = s.size();

    int a[n] = {}, b[n] = {};
    int next[54] = {};
    int in[54] = {};
    fill(next, next + 54, -1);
    set<char> all;

    for (int i = 0; i < n; i++)
        a[i] = ci(s[i]),
        b[i] = ci(t[i]),
        all.insert(b[i]);

    bool poss = true;
    for (int i = 0; i < n; i++) {
        if (next[a[i]] != -1 && b[i] != next[a[i]])
            poss = false;
        next[a[i]] = b[i];
    }

    if (all.size() == 52)
        poss = false;

    if (s == t)
        poss = true;

    if (!poss) {
        cout << -1 << nl;
        return;
    }

    int ans = 0;
    for (int i = 0; i < 52; i++)
        if (next[i] != -1 && next[i] != i)
            in[next[i]]++, ans++;

    int vis[53] = {};
    for (int i = 0; i < 52; i++) {
        if (!vis[i]) {
            int a = i;
            while (a != -1 && !vis[a])
                vis[a] = i + 1, a = next[a];

            if (vis[a] == i + 1 && a != -1 && a != next[a]) {
                int s = a;
                bool skip = false;
                do {
                    a = next[a];
                    if (in[a] > 1) skip = true;
                } while (a != s);
                
                ans += !skip;
            }
        }
    }

    cout << ans << nl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t; cin >> t;
    while (t--)
        solve();
}