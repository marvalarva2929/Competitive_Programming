using namespace std;
#include <bits/stdc++.h>
#define int long long
#define nl '\n'
int id[27];
int sz[27];
int out[27];
int in[27];

const string letters = "#abcdefghijklmnopqrstuvwxyz";
unordered_map<char, int> cti;

int root(int i) {
    while (i != id[i]) {
        i = id[i];
        id[i] = id[id[i]];
    }
    return i;
}

void ct(int x, int y) {
    x = root(x), y = root(y); 
    if (sz[y] > sz[x]) 
        swap(x, y);
    
    sz[x] += sz[y];
    id[y] = x;
}

void solve() {
    iota(id, id + 27, 0);
    fill(sz, sz + 27, 1);
    fill(out, out + 27, 0);
    fill(in, in + 27, 0);

    int n; string ss; cin >> n >> ss;

    int s[n] = {};
    for (int i = 0; i < n; i++)
        s[i] = cti[ss[i]];

    // cout << sz[26] << nl;

    unordered_map<int, char> assignment;

    for (int i = 0; i < n; i++) 
        if (!assignment[s[i]]) {
            bool ok = false;
            int assign;
            for (int j = 1; j <= 26; j++) {
                if ((root(j) != root(s[i]) && !out[j])) { ok = true; assign = j; break; }
            }

            ct(s[i], assign);
            out[assign] = 1;
            in[s[i]]++;

            if (ok) {
                assignment[s[i]] = letters[assign];
            } else {
                for (int j = 1; j <= 26; j++)
                    if (!out[j])
                        assignment[s[i]] = letters[j];
            }
        }
        
    
    for (int i = 0; i < n; i++)
        cout << assignment[cti[ss[i]]];
    cout << nl;
    return;

}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    for (int i = 0; i < 26; i++)
        cti['a' + i] = i + 1;

    int t; cin >> t;
    while (t--)
        solve();
}